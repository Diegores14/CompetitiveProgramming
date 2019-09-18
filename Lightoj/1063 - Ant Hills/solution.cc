#include <bits/stdc++.h>
using namespace std;
const int tam = 10005;
int n, m, timer, tin[tam], low[tam];
bool used[tam];
list< int > G[tam];
set<int> ans;

void DFS( int idx, int p = -1 ) {
    used[idx] = true;
    tin[idx] = low[idx] = timer++;
    int children = 0;
    for( int to: G[idx] ) {
        if( to == p ) continue;
        if( used[to] ) {
            low[idx] = min( low[idx], tin[to] );
        } else { 
            DFS( to, idx );
            low[idx] = min( low[idx], low[to] ) ;
            if( tin[idx] <= low[to] && p != -1) {
                ans.insert(idx);
            }
            children++;
        }
    }
    if( children > 1 && p == -1 ) {
        ans.insert(idx);
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        timer = 0;
        ans.clear();
        memset( used, 0, sizeof used );
        for( int i = 0; i < tam; i++ ) {
            G[i].clear();
        }
        cin >> n >> m;
        for( int i = 0; i < m; i++ ) {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for( int i = 1; i <= n; i++ ) {
            if( !used[i] ) {
                DFS(i);
            }
        }
        cout << "Case " << cases << ": " << ans.size() << '\n';
    }
    return 0;
}