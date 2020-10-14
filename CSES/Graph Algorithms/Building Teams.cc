#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+7;
vector< vector< int > > g(tam);
bool ans = true;
int team[tam];
 
void DFS( int u, int flag = 1 ) {
    team[u] = flag;
    for( int v: g[u] ) {
        if( team[v] == 0 ) {
            DFS(v, flag==1? 2: 1 );
        } else {
            ans &= team[v] == (flag==1? 2: 1);
        }
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
    for( int i = 1; i <= n; i++ ) {
        if( team[i] == 0 ) DFS( i );
    }
    if( ans ) {
        for( int i = 0; i <= n; i++ ) {
            cout << team[i+1] << (i+1==n? '\n' : ' ');
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}