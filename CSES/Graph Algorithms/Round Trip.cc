#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+7;
vector< vector< int > > g(tam);
bool ans = true;
bool used[tam];
int level[tam], p[tam];
int l, r;
 
bool DFS( int u, int sz = 1) {
    used[u] = true;
    level[u] = sz;
    for( int v: g[u] ) {
        if( !used[v] ) {
            p[v] = u;
            if( DFS(v, sz+1) ) return true;
        } else {
            if(p[u] != v) {
                l = v;
                r = u;
                return true;
            }
        }
    }
    return false;
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
        if( !used[i] ) {
            p[i] = i;
            if( DFS( i ) ) {
                vector< int > v[2];
                while( l != r ) {
                    if( level[l] == level[r] ) {
                        v[0].push_back(l); v[1].push_back(r);
                        l = p[l];
                        r = p[r];
                    } else {
                        if( level[l] < level[r] ) {
                            v[1].push_back(r);
                            r = p[r];
                        } else {
                            v[0].push_back(l);
                            l = p[l];
                        }
                    }
                }
                if( v[0].empty() || v[0].back() != l ) v[0].push_back(l);
                if( v[1].empty() || v[1].back() != l ) v[1].push_back(l);
                reverse( v[0].begin(), v[0].end() );
                cout << v[0].size()+v[1].size() << '\n';
                for( int i = 0; i < v[0].size(); i++ ) {
                    cout << (i? " " : "" ) << v[0][i];
                }
                for( int i: v[1] ) {
                    cout << ' ' << i;
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}