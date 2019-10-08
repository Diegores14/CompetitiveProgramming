#include <bits/stdc++.h>
using namespace std;
const int tam = 210;
list< int > g[tam];
int match[tam];
bool used[tam];
int it = 0;

int dfs( int idx ) {
    for( int k: g[idx] ) {
        if(used[k]) continue;
        used[k] = true;
        if( match[k] == -1 || dfs(match[k]) ) {
            match[k] = idx;
            return 1;
        }
    }
    return 0;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        for( int i = 0; i < tam; i++ ) {
            g[i].clear();
        }
        cin >> n;
        int v1[n];
        for( int i = 0; i < n; i++ ) {
            cin >> v1[i];
        }
        cin >> m;
        int v2[m];
        for( int i = 0; i < m; i++ ) {
            cin >> v2[i];
        }
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                if( v2[j]%v1[i] == 0 ) {
                    g[i].push_back( j+n );
                    //g[j+n].push_back( i );
                }
            }
        }
        int ans = 0;
        memset( match, -1, sizeof match );
        for( int i = 0; i < n; i++ ) {
            memset( used, 0, sizeof used );
            ans += dfs( i );
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}