#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
typedef vector< vector< int > > matriz;

/* 
    f(n) = a*f(n-1)+ 0*f(n-2) + b*f(n-3) + c;
    f(n-1) = f(n-1);
    f(n-2) = f(n-2);
    1 = 1;
*/

matriz operator *( matriz a, matriz b ) {
    matriz ans( 4, vector< int >(4, 0) );
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            for( int k = 0; k < 4; k++ ) {
                ans[i][j] = ( ans[i][j] + a[i][k]*b[k][j] )%mod;
            }
        }
    }
    return ans;
}

int exp( int n, int v[3] ) {
    matriz ans(4, vector< int >(4, 0) ), pro(4, vector< int > (4, 0) );
    for( int i = 0; i < 4; i++ ) ans[i][i] = 1;
    pro[0][0] = v[0]; pro[0][2] = v[1]; pro[0][3] = v[2];
    pro[1][0] = 1; pro[2][1] = 1; pro[3][3] = 1;
    while( n ) {
        if( n&1 ) {
            ans = ans*pro;
        }
        n >>= 1;
        pro = pro*pro;
    }
    return ans[0][3];
}

void solve() {
    int n, v[3];
    cin >> n >> v[0] >> v[1] >> v[2];
    if( n <= 2 ) {
        cout << 0 << '\n';
    } else {
        v[0] %= mod;
        v[1] %= mod;
        v[2] %= mod;
        cout << exp( n-2, v ) << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}