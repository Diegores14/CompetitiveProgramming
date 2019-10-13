#include <bits/stdc++.h>
using namespace std;
const int tam = 1001;
double dp[tam][tam];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset( dp, 0, sizeof dp );
    for( int i = 0; i < tam; i++ ) dp[0][i] = 1;
    for( int i = 1; i < tam; i++ ) {
        for( int j = 0; j < tam; j++ ) {
            double a = 0, b = ((i+j+1)*(i+j))/2;
            if( i >= 2 ) { a += (dp[i-2][j]*i*(i-1))/2; }
            if( j >= 2 ) { b -= double(j*(j-1))/2; }
            if( j >= 1 ) {
                a += i*j*dp[i][j-1];
                b -= j;
            }
            dp[i][j] = a/b;
        }
    }
    int t, x, y; 
    cout << fixed << setprecision(10);
    cin >> t; 
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> x >> y;
        cout << "Case " << cases << ": " << dp[x][y] << '\n';
    }
    return 0;
}