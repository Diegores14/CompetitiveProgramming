#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef vector< vector< ULL > > matriz;

/* 
    a^2+b^2 = (a+b)*(a+b) - (a^0+b^0)*ab = a^2 + ab + ab + b^2 - ab - ab;
    a^3+b^3 = (a^2+b^2)*(a+b) - (a^1+b^1)*ab = a^3 + ab^2 + a^2b + b^3 - a^2b - ab^2;
    f( n ) = (a+b)*f(n-1) - ab*f(n-2);
    f( n-1 ) = f(n-1);
*/
/*
ULL mul( ULL a, ULL b ) {
    if( a == 0 ) return a;
    if( a&1 ) {
        return ( (( 2*mul( a/2, b ) )%mod * b)%mod + b )%mod;
    } else {
        return ( ( 2*mul( a/2, b ) )%mod * b)%mod;
    }
}*/

matriz operator *( matriz a, matriz b ) {
    matriz ans(2, vector<ULL>(2, 0) );
    int len = 2;
    for( int i = 0; i < len; i++ ) {
        for( int j = 0; j < len; j++ ) {
            for( int k = 0; k < len; k++ ) {
                ans[i][j] = ans[i][j] + a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

ULL exp( ULL p, ULL q, int n ) {
    if( n < 0 ) return 2;
    matriz ans(2, vector< ULL >(2, 0) ), pro( 2, vector< ULL >(2, 0 ) );
    pro[0][0] = p; pro[0][1] = -q;
    pro[1][0] = 1;
    ans[0][0] = ans[1][1] = 1;
    while( n ) {
        if( n&1 ) {
            ans = ans*pro;
        }
        n >>= 1;
        pro = pro*pro;
    }
    return ans[0][0]*p + ans[0][1]*2;
}

void solve() {
    ULL p, q;
    int n; 
    cin >> p >> q >> n;
    cout << exp( p, q, n-1) << '\n';
}

int main() {
    //ios_base::sync_with_stdio( false ); cin.tie( NULL );
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}