#include <bits/stdc++.h>
using namespace std;

/*
i -> indistinguishable, j -> distinguishable
n1 = cantidad indistinguishable
rest = n1+n2-j
P[n1][n2] = 0
p[i][j] = ((n2-j)/rest)*(p[i][j+1]+avg2) + ((n1-i)/rest)*(p[i+1][j]+avg1) + (i/rest)*(p[i][j]+avg1)
rest*p[i][j] = (n2-j)*(p[i][j+1]+avg2) + (n1-i)*p[i+1][j] + i*p[i][j] + n1*avg1
p[i][j] = ((n2-j)*(p[i][j+1]+avg2) + (n1-i)*p[i+1][j] + n1*avg1)/(rest-i)

*/

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cout << fixed << setprecision( 10 );
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        int n, a, b, n1 = 0, n2 = 0, sum1 = 0, sum2 = 0;
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            cin >> a >> b;
            if( b == 1 ) {
                n2++;
                sum2 += a;
            } else {
                n1++;
                sum1 += a;
            }
        }
        double avg1 = 0, avg2 = 0;
        if( n1 )
            avg1 = double(sum1)/n1;
        if( n2 )
            avg2 = double(sum2)/n2;
        double dp[2][n2+2];
        memset( dp, 0, sizeof dp );
        int flag = 0;
        for( int i = n1; i >= 0; i-- ) {
            for( int j = n2 - (n1 == i); j >= 0; j-- ) {
                dp[flag][j] = 0;
                if( j+1 <= n2 ) dp[flag][j] += double(n2-j)*(dp[flag][j+1]+avg2);
                //cout << i << ' ' << j << " Debug " << dp[i][j] << ' ' << n-j-i << '\n';
                if( i+1 <= n1 ) dp[flag][j] += double(n1-i)*dp[flag^1][j];
                //cout << i << ' ' << j << " Debug " << dp[i][j] << ' ' << n-j-i << '\n';
                dp[flag][j] += double(n1)*avg1;
                //cout << "Debug " << dp[i][j] << ' ' << n-j-i << '\n';
                if( n-j-i >= 0)
                    dp[flag][j] /= (n-j-i);
            }
            flag ^= 1;
        }
        cout << "Case " << cases << ": " << dp[flag^1][0] << '\n';
    }
    return 0;
}