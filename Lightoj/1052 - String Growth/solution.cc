#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef vector< vector< long long > > matriz;

/*
    Equation for resolve this problem
    cantA(n) = 0*cantA(n-1) + 1*cantB(n-1)
    cantB(n) = 1*cantA(n-1) + 1*cantB(n-1)
*/

matriz operator *( matriz a, matriz b ) {
    matriz ans(2,  vector< long long >(2, 0) );
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 2; j++ ) {
            for( int k = 0; k < 2; k++ ) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;
}

vector< long long > exp( int n ) {
    matriz pro( 2, vector< long long >(2, 1) ), ans(2, vector< long long >(2) );
    pro[0][0] = 0;
    ans[0][0] = ans[1][1] = 1;
    while( n ) {
       if( n&1 ) {
           ans = ans*pro;
       }
       n >>= 1;
       pro = pro*pro;
    }
    ans[0][0] += ans[1][0];
    ans[0][1] += ans[1][1];
    return ans[0];
}

bool resolve( vector< long long > a, vector< long long > b, vector< long long > &ans ) {
    ans.assign( 2, 0 );
    long long Delta = a[0]*b[1] - b[0]*a[1];
    if( Delta == 0 ) return false;
    long long d1 = a[2]*b[1] - b[2]*a[1];
    long long d2 = a[0]*b[2] - b[0]*a[2];
    ans[0] = d1/Delta;
    ans[1] = d2/Delta;
    return d1%Delta == 0 && d2%Delta == 0 && ans[0] >= 0 && ans[1] >= 0;
}

void solve() {
    int n, x, m, y, k;
    cin >> n >> x >> m >> y >> k;
    vector< long long > e1 = exp( n-1 ), e2 = exp( m-1 );
    e1.push_back(x);
    e2.push_back(y);
    //cout << "equation1 " << e1[0] << ' ' << e1[1] << ' ' << e1[2] << '\n';
    //cout << "equation2 " << e2[0] << ' ' << e2[1] << ' ' << e2[2] << '\n';
    vector< long long > ans;
    if( resolve( e1, e2, ans ) ) {
        //cout << "solution " << ans[0] << ' ' << ans[1] << '\n';
        e1 = exp( k-1 );
        cout << ( (e1[0]*ans[0])%mod + (e1[1]*ans[1])%mod )%mod << '\n';
    } else {
        cout << "Impossible\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}