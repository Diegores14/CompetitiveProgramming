#include <bits/stdc++.h>
using namespace std;
typedef vector< vector< int > > matriz;
int mod1;

matriz identidad( int n ) {
    matriz ans( n, vector< int >(n, 0) );
    for( int i = 0; i < n; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

matriz operator *( matriz a, matriz b ) {
    int n = a.size();
    matriz ans( n, vector< int >(n, 0) );
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            for( int k = 0; k < n; k++ ) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod1;
            }
        }
    }
    return ans;
}

int exp( const int a, const int b, int n, const int mod) {
    if( n == -1 ) return a;
    matriz ans = identidad(2);
    matriz pro(2, vector< int >(2, 1) );
    pro[1][1] = 0;
    while( n ) {
        if( n&1 ) {
            ans = ans*pro;
        }
        n >>= 1;
        pro = pro*pro;
    }
    return (ans[0][0]*b + ans[0][1]*a)%mod;
}

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    int mod = 1;
    for( int i = 0; i < m; i++ ) mod *= 10;
    mod1 = mod;
    cout << exp( a, b, n-1, mod ) << '\n';
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