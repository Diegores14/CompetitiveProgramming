#include <bits/stdc++.h>
using namespace std;
const int tam = 3e5;
vector< vector< int > > g(tam);
bool used[tam];
int pre[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for( int i = 0, a, b; i < m; i++ ) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue< int > q;
    q.push(1);
    used[1] = true;
    pre[1] = -1;
    while( !q.empty() ) {
        int u = q.front();
        q.pop();
        if( u == n ) break;
        for( int v: g[u] ) {
            if( !used[v] ) {
                q.push(v);
                pre[v] = u;
                used[v] = true;
            }
        }
    }
    if( pre[n] == 0 ) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector< int > ans;
    int node = n;
    while( node != -1 ) {
        ans.push_back(node);
        node = pre[node];
    }
    reverse( ans.begin(), ans.end() );
    cout << ans.size() << '\n';
    for( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << (i+1 == ans.size()? '\n' : ' ');
    }
    return 0;
}