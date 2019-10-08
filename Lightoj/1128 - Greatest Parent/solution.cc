#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+10, tam1 = 18;
list< int > g[tam];
//int tin[ tam ], tout[ tam ];
int value[tam], up[tam][tam1];
//int timer;

void dfs( int idx, int p ) {
    up[idx][0] = p;
    for( int i = 1; i < tam1; i++ ) {
        up[idx][i] = up[up[idx][i-1]][i-1];
    }
    for( int k: g[idx] ) {
        if( k == p ) continue;
        dfs( k, idx );
    }
}

void solve() {
    for( int i = 0; i < tam; i++ ) {
        g[i].clear();
    }
    int n, q, p, s;
    scanf("%d %d", &n, &q);
    value[0] = 1;
    for( int i = 1; i < n; i++ ) {
        scanf("%d %d", &p, &value[i]);
        g[p].push_back( i );
    }
    dfs( 0, 0 );
    while( q-- ) {
        scanf("%d %d", &p, &s);
        for( int i = tam1-1; i >= 0; i-- ) {
            if( value[ up[p][i] ] >= s ) {
                p = up[p][i];
            }
        }
        printf("%d\n", p); 
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":\n";
        solve();
    }
    return 0;
}