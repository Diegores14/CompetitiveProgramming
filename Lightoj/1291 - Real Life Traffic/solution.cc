#include <bits/stdc++.h>
using namespace std;
const int tam = 10005;
int n, m, timer, tin[tam], low[tam], col;
list< int > G[tam];
bool used[tam];
int color[tam];
int cant[tam];
stack< int > s;

void DFS( int idx, int p = -1 ) {
    used[idx] = true;
    tin[idx] = low[idx] = timer++;
    s.push( idx );
    for( int &to: G[idx] ) {
        if( to == p ) continue;
        if( used[to] ) {
            low[idx] = min( low[idx], tin[to] );
        } else {
            DFS( to, idx );
            low[idx] = min( low[idx], low[to] );
        }
    }
    if( low[idx] == tin[idx] ) {
        col++;
        while( !s.empty() ) {
            int u = s.top();
            s.pop();
            color[u] = col;
            if( u == idx ) break;
        }
    }
}

int solve() {
    DFS(0);
    memset( cant, 0, sizeof cant );
    for( int i = 0; i < n; i++ ) {
        for( int j: G[i] ) {
            if( color[i] != color[j] ) {
                cant[color[i]]++;
                cant[color[j]]++;
            }
        }
    }
    int ans = 0;
    for( int i = 1; i <= col; i++ ) {
        ans += (cant[i] == 2);
    }
    return (ans+1)/2;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        timer = 0;
        col = 0;
        while( !s.empty() ) { s.pop(); }
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
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}