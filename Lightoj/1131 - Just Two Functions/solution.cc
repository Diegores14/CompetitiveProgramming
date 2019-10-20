#include <bits/stdc++.h>
using namespace std;
int mod;
typedef vector< vector< long long > > matriz;

/*
    f(n) = a1*f(n-1) + b1*f(n-2) + c1*g(n-3)
    g(n) = a2*g(n-1) + b2*g(n-2) + c2*f(n-3)
    | f( n ) | = |a1, b1, 0, 0, 0, c1 |*| f(n-1) |
    | f(n-1) | = | 1,  0, 0, 0, 0,  0 | | f(n-2) |
    | f(n-2) | = | 0,  1, 0, 0, 0,  0 | | f(n-3) |
    | g( n ) | = |0, 0, c2, a2, b2, 0 | | g(n-1) |
    | g(n-1) | = | 0,  0, 0, 1, 0,  0 | | g(n-2) |
    | g(n-2) | = | 0,  0, 0, 0, 1,  0 | | g(n-3) |
*/
 
matriz operator *( matriz &a, matriz &b ) {
    matriz ans ( 6, vector< long long >(6, 0) );
    for( int i = 0; i < 6; i++ ) {
        for( int j = 0; j < 6; j++ ) {
            for( int k = 0; k < 6; k++ ) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;
}
 
matriz identidad( int n ) {
    matriz ans(n, vector< long long > (n, 0 ) ); 
    for( int i = 0; i < n; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

matriz exp( matriz b, int n ) {
    matriz ans = identidad(6);
    while( n ) {
        if( n&1 ) {
            ans = ans*b;
        }
        n >>= 1;
        b = b*b;
    }
    return ans;
}

void print( matriz &v ) {
    cout << "matriz\n";
    for( int i = 0; i < v.size(); i++ ) {
        for( int j = 0; j < v[i].size(); j++ ) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    matriz v(6, vector< long long >(6, 0) );
    cin >> v[0][0] >> v[0][1] >> v[0][5];
    cin >> v[3][3] >> v[3][4] >> v[3][2];
    v[1][0] = 1;
    v[2][1] = 1;
    v[4][3] = 1;
    v[5][4] = 1;
    long long f[3], g[3], q, n;
    cin >> f[0] >> f[1] >> f[2] >> g[0] >> g[1] >> g[2];
    cin >> mod;
    f[0] %= mod;
    f[1] %= mod;
    f[2] %= mod;
    g[0] %= mod;
    g[1] %= mod;
    g[2] %= mod;
    //print( v );
    cin >> q;
    while( q-- ) {
        cin >> n;
        if( n > 2 ) {
            matriz temp = exp( v, n-2 );
            //print( temp );
            cout << (temp[0][0]*f[2] + temp[0][1]*f[1] + temp[0][2]*f[0] + temp[0][3]*g[2] + temp[0][4]*g[1] + temp[0][5]*g[0])%mod << ' ' << 
                    (temp[3][0]*f[2] + temp[3][1]*f[1] + temp[3][2]*f[0] + temp[3][3]*g[2] + temp[3][4]*g[1] + temp[3][5]*g[0])%mod << '\n';
        } else {
            cout << f[n] << ' ' << g[n] << '\n';
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":\n";
        solve();
    }
    return 0;
}