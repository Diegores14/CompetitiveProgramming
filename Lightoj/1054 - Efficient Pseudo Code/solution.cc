#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5;
const int tam1 = 9592;
const int mod = 1e9+7;
bool sieve[tam];
long long primes[tam1];

long long exponentation(long long b, long long e) {
    long long ans = 1;
    long long pro = b%mod;
    while( e ) {
        if( e&1 ) ans = ( ans*pro )%mod; 
        pro = ( pro*pro )%mod;
        e >>= 1;
    }
    return ans;
}

long long suma(long long a, long long b) {
    return ( ((exponentation(a, b+1) - 1 + mod)%mod) * ( exponentation(a-1, mod-2) ) )%mod;
}

long long solve(long long n, long long m) {
    long long ans = 1;
    for(int i = 0; i < tam1 && primes[i]*primes[i] <= n; i++) {
        if( n%primes[i] == 0 ) {
            long long temp = 0;
            while( n%primes[i] == 0 ) {
                n /= primes[i];
                temp++;
            }
            ans = ( ans * suma(primes[i], m*temp) ) % mod;
        }
    }
    if( n > 1) ans = ( ans * suma(n, m) ) % mod;
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m, t;
    int len = 0;
    memset( sieve, -1, sizeof sieve);
    for(long long i = 2; i < tam; i++) {
        if( sieve[i] ) {
            primes[len++] = i;
            for(long long j = i*i; j < tam; j += i) {
                sieve[j] = false;
            }
        }
    }
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n >> m;
        cout << "Case " << cases << ": ";
        if(m == 0) {
            cout << 1 << '\n';
        } else {
            cout << solve(n, m) << '\n';
        }
    }
    return 0;
}