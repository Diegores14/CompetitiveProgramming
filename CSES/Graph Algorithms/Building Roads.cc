#include <bits/stdc++.h>
using namespace std;
vector< vector< int > > g(300000);
bool used[300000];

void DFS( int u ) {
    used[u] = true;
    for( int v: g[u] ) {
        if( !used[v])
            DFS(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for( int i = 0, a, b; i < m; i++ ) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector< int > ans;
    for( int i = 1; i <= n; i++ ) {
        if( !used[i] ) {
            DFS(i);
            ans.push_back(i);
        }
    }
    cout << ans.size()-1 << '\n';
    for( int i = 1; i < ans.size(); i++ ) {
        cout << 1 << ' ' << ans[i] << '\n';
    }
    return 0;
}
