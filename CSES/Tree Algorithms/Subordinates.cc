#include <bits/stdc++.h>
using namespace std;
vector< vector< int > > g(300000);
int cnt[300000];
 
int DFS( int u = 0 ) {
    for( int v: g[u] ) {
        cnt[u] += DFS(v)+1;
    }
    return cnt[u];
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    for( int i = 1, a; i < n; i++ ) {
        cin >> a; a--;
        g[a].push_back(i);
    }
    DFS();
    for( int i = 0; i < n; i++ ) {
        cout << cnt[i] << (i+1==n? '\n': ' ');
    }
    return 0;
}
