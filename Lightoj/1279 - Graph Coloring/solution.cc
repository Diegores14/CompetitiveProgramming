#include <bits/stdc++.h>
using namespace std;
const int tam = 100;
long long ecuation[tam][tam];
long long n, m, k;

long long exp( long long b, long long e, long long mod = 1e9+7) {
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

void cambiar( int i, int j ) {
    for( int k = 0; k < n; k++ ) {
        swap( ecuation[i][k], ecuation[j][k] );
    }
}

void dividir( long long line, long long inv ) {
    for( int i = 0; i < n; i++ ) {
        ecuation[line][i] = (ecuation[line][i]*inv + k)%k;
    }
}

void  print() {
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cout << ecuation[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "---------\n";
}

int gauss() {
    int ans = 0, i = 0, r = 0;
    while( i < n && r < n ) {
        if( ecuation[r][i] == 0 ) {
            for( int j = r+1; j < n; j++ ) {
                if( ecuation[j][i] ) {
                    cambiar( r, j );
                    break;
                }
            }
        }
        if( ecuation[r][i] ) {
            long long inv = exp( (ecuation[r][i] + k)%k, k-2, k );
            dividir( r, inv );
            for( int j = 0; j < n; j++ ) {
                if( j != r && ecuation[j][i] != 0 ) {
                    long long t = ecuation[j][i];
                    for( int c = 0; c < n; c++ ) {
                        ecuation[j][c] = ( (ecuation[j][c]-t*ecuation[r][c])%k + k )%k;
                    }
                }
            }
            r++;
        } else {
            ans++;
        }
        i++;
    }
    return ans;
}

void solve() {
    int a, b;
    cin >> n >> m >> k;
    memset( ecuation, 0, sizeof ecuation );
    for( int i = 0; i < n; i++ ) { ecuation[i][i] = 1; }
    for( int i = 0; i < m; i++ ) {
        cin >> a >> b; a--; b--;
        ecuation[a][b] = k-1;
        ecuation[b][a] = k-1;
    }
    long long r = gauss();
    //print();
    cout << exp( k, r ) <<  '\n';
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