#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
const int tam = 10005;
list< int > G[tam];
int used[tam];
int tin[tam], low[tam];
int n, timer;
vector< ii > bridges;

int DFS( int idx, int p = -1 ) {
    used[idx] = true;
    tin[idx] = low[idx] = timer++;
    for( int &to: G[idx] ) {
        if( to == p ) continue;
        if( used[to] ) {
            low[idx] = min( low[idx], low[to] );
        } else {
            DFS( to, idx );
            low[idx] = min( low[idx], low[to] );
            if(  tin[idx] < low[to] ) {
                if( idx < to )
                    bridges.push_back( ii(idx, to) );
                else
                    bridges.push_back( ii( to, idx ) );
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, k, b;
    char c;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        timer = 0;
        memset( used, 0, sizeof used );
        bridges.clear();
        for( int i = 0; i < tam; i++ ) {
            G[i].clear();
        }
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            cin >> a >> c >> k >> c;
            //cout << a << '\n';
            for( int j = 0; j < k; j++ ) {
                cin >> b;
                G[a].push_back(b);
            }
        }
        for( int i = 0; i < n; i++ ) {
            if( !used[i] ) {
                DFS(i);
            }
        }
        sort( bridges.begin(), bridges.end() );
        cout << "Case " << cases << ":\n";
        cout << bridges.size() << " critical links\n";
        for( ii i: bridges ) {
            cout << i.first << " - " << i.second << '\n';
        }
    }
    return 0;
}