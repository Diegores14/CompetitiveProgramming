#include <bits/stdc++.h>
using namespace std;
const int tam = 100010, mod = 1e9+7;
int p[tam][20];
long long val[tam][20];
long long x[tam];
int prof[tam];
list< int > G[tam];
int n;

long long gcd( long long a, long long b ) {
    return b? gcd(b, a%b ): a;
}

void dfs( int idx, int par ) {
    p[idx][0] = par; val[idx][0] = x[idx];
    prof[idx] = prof[par] + 1;
    for( int &i: G[idx] ) {
        if( i == par ) continue;
        dfs( i, idx );
    }
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> x[i];
    }
    for( int i = 1; i < n; i++ ) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs( 1, 0 );
    // Borrar Despues para ver que pasa.
    /* for( int i = 0; i < 20; i++ ) {
        val[0][i] = 1;
    }*/
    for( int i = 1; i < 20; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            int parent = p[j][i-1];
            p[j][i] = p[ parent ][i-1];
            val[j][i] = gcd( val[j][i-1], val[ parent ][i-1] );
        }
    }
    long long ans = 0;
    for( int i = 1; i <= n; i++ ) {
        int u = i;
        long long d = x[u];
        while( u ) {
            int v = u;
            for( int j = 19; j >= 0; j-- ) {
                if( prof[v] >= (1<<j) && ( (d == 0 && val[v][j] == 0) || ( d != 0 && val[v][j]%d == 0 ) ) ) {
                    v = p[v][j];
                }
            }
            ans = (ans+ ( (d%mod)*(prof[u]-prof[v])%mod )%mod)%mod;
            u = v;
            d = gcd(d, x[u]);
        }
    }
    cout << ans << '\n';
    return 0;
}