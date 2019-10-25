#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
typedef vector< vector< int > > matriz;
matriz base(4, vector< int >(4, 0) );

matriz operator *( matriz &a, matriz &b ) {
    int n = a.size();
    matriz ans( n, vector< int >( n, 0 ) );
    for( int i = 0; i < n; i++ ) 
        for( int j = 0; j < n; j++ ) 
            for( int k = 0; k < n; k++ ) 
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
    return ans;
}

matriz identidad( int n ) {
    matriz ans(n, vector< int >(n,0) );
    for( int i = 0; i < n; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

int exp( matriz b, int e ) {
    matriz ans = identidad(4);
    while( e ) {
        if( e&1 ) {
            ans = ans*b;
        }
        e >>= 1;
        b = b*b;
    }
    return ((ans[0][0]*2) + ans[0][1] + ans[0][2] + ans[0][3] )%mod;
}

void solve() {
    int n;
    cin >> n;
    if( n <= 2 ) {
        if( n == 2 ) cout << 2 << '\n';
        else  cout << 1 << '\n';
    } else {
        cout << exp( base, n-2 ) << '\n';
    }
}

void print( matriz v ) {
    for( int i = 0; i < 4; i++ ) {
        for( int j = 0; j < 4; j++ ) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    base[0][0] = base[0][2] = base[0][1] = base[1][0] = base[0][3] = 1;
    base[2][1] = base[2][3] = base[3][1] = base[3][2] = 1;
    //print( base );
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}