#include <bits/stdc++.h>
using namespace std;
int primes[100];
int sz = 0, n;
const int mod = 1e9+7, tam = 1005;
int v[64][tam];

void get_primes() {
    int len = 301;
    bool sieve[len];
    memset( sieve, -1, sizeof sieve );
    sieve[0] = sieve[1] = 0;
    for( int i = 2; i < len; i++ ) {
        if( sieve[i] ) {
            primes[sz++] = i;
            for( int j = i*i; j < len; j += i ) {
                sieve[j] = 0;
            }
        }
    }
}

long long exp( long long b, long long e ) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans*b)%mod;
        }
        e >>= 1;
        b = (b*b)%mod;
    }
    return ans;
}

int gauss() {
    int i = 0, r = 0;
    while( i < n && r < sz ) {
        if( v[r][i] == 0 ) {
            for( int k = r+1; k < sz; k++ ) {
                if( v[k][i] ) {
                    for( int j = 0; j < n; j++ ) {
                        swap( v[r][j], v[k][j] );
                    }
                    break;
                }
            }
        }
        if( v[r][i] ) {
            for( int k = r+1; k < sz; k++ ) {
                if( v[k][i] ) {
                    for( int j = 0; j < n; j++ ) {
                        v[k][j] ^= v[r][j];
                    }
                }
            }
            r++;
        }
        i++;
    }
    return r;
}

void solve() {
    long long temp;
    cin >> n;
    memset( v, 0, sizeof v );
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        for( int j = 0; j < sz; j++ ) {
            while( temp%primes[j] == 0 ) {
                v[j][i] ^= 1;
                temp /= primes[j];
            }
        }
    }
    int r = gauss();
    cout << exp( 2, n-r ) - 1 << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    get_primes();
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}