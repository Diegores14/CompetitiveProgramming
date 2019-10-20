#include <bits/stdc++.h>
using namespace std;
const int mod = 10;
typedef vector< vector < int > > matriz;
typedef vector< vector< matriz > > matrizM;

/*
    suma( A^i ) = 1 + A + A^2 + A^3 + A^4 + A^5;
    f(n)   = A*f(n-1) + 1;
    1      = 1
    ********************************
    f(n)   = | A , 1 | * | f(n-1) |
    1      = | 0 , 1 |   |    1   |
    ********************************
*/

matriz operator *( matriz a, matriz b ) {
    int n = a.size();
    matriz ans( n, vector< int >(n, 0) );
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            for( int k = 0; k < n; k++ ) {
                ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
        }
    }
    return ans;
}

matriz operator +( matriz a, matriz b ) {
    int n = a.size();
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            a[i][j] = (a[i][j]+b[i][j])%mod;
        }
    }
    return a;
}

matrizM operator *( matrizM a, matrizM b ) {
    int n = a[0][0].size();
    matrizM ans( 2, vector< matriz >(2, matriz(n, vector<int>(n, 0) ) ) );
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 2; j++ ) {
            for( int k = 0; k < 2; k++ ) {
                ans[i][j] = ans[i][j] + a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

matriz identidad( int n ) {
    matriz ans( n, vector< int > (n, 0) );
    for( int i = 0; i < n; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

matriz zeros( int n ) {
    return matriz( n, vector< int > (n, 0) );
}

void print2( matriz v ) {
    int n = v.size();
    cout << "************************\n";
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

void print( matrizM v ) { 
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < 2; j++ ) {
            print2( v[i][j] );
        }
    }
}

matriz exp( int n, int e, matriz A) {
    matrizM ans(2, vector<matriz>(2) ), pro(2, vector<matriz>(2) );
    ans[0][0] = identidad( n ); pro[0][0] = A;
    ans[1][1] = identidad( n ); pro[1][1] = identidad( n );
    ans[0][1] = zeros( n ); pro[0][1] = identidad( n );
    ans[1][0] = zeros( n ); pro[1][0] = zeros( n );
    while( e ) {
        if( e&1 ) {
            ans = ans*pro;
        }
        e >>= 1;
        pro = pro*pro;
    }
    //print( ans );
    return ans[0][0] + ans[0][1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    matriz A = zeros(n);
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin >> A[i][j];
            A[i][j] %= mod;
        }
    }
    matriz ans = exp( n, k-1, A)*A;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":\n";
        solve();
    }
    return 0;
}