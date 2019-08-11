#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6+5;
long long factorial[tam], invFactorial[tam];
const int mod = 1e6+3;

long long exponentation( long long b, long long e ) {
    long long ans = 1;
    long long pro = b;
    while( e ) {
        if( e&1 ) {
            ans = (ans*pro)%mod;
        }
        pro = (pro*pro)%mod;
        e >>= 1;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    factorial[0] = 1;
    invFactorial[0] = exponentation( 1, mod-2 );
    for(long long i = 1; i <= 1e6; i++) {
        factorial[i] = ( i*factorial[i-1] )%mod;
        invFactorial[i] = exponentation( factorial[i], mod-2 );
    }
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n >> k;
        cout << "Case " << cases << ": " << (factorial[n]*invFactorial[n-k]*invFactorial[k])%mod << '\n';
    }
    return 0;
}