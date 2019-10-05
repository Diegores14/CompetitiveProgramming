#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge {
    int u, v;
    LL cap, flow;
    edge() {}
    edge( int u, int v, LL cap ): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
    int N;
    vector< edge > E;
    vector< vector< int > > g;
    vector< int > d, pt;
    dinic( int N ): N(N), E(0), g(N), d(N), pt(N) {}
    void add_edge( int u, int v, LL cap ) {
        if( u != v ) {
            E.push_back( edge(u, v, cap) );
            g[u].push_back( E.size() - 1 );
            E.push_back( edge(v, u, 0) );
            g[v].push_back( E.size() - 1 );
        }
    }
    bool bfs( int S, int T ) {
        queue< int > q({S});
        fill( d.begin(), d.end(), N+1 );
        d[S] = 0;
        while( !q.empty() ) {
            int u = q.front(); q.pop();
            if( u == T ) break;
            for( int &k: g[u] ) {
                edge &e = E[k];
                if( e.flow < e.cap && d[e.v] > d[e.u]+1 ) {
                    d[e.v] = d[e.u]+1;
                    q.push( e.v );
                }
            }
        }
        return d[T] != N+1;
    } 
    LL dfs( int u, int T, LL flow = -1 ) {
        if( u == T || flow == 0 ) return flow;
        for( int &i = pt[u]; i < int(g[u].size()); i++ ) {
            edge &e = E[g[u][i]];
            edge &oe = E[g[u][i]^1];
            if( d[e.v] == d[e.u]+1 ) {
                LL amt = e.cap - e.flow;
                if( flow != -1 && flow < amt ) amt = flow;
                if( LL pushed = dfs( e.v, T, amt ) ) {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    LL max_flow( int S, int T ) {
        LL total = 0;
        while( bfs(S, T) ) {
            fill( pt.begin(), pt.end(), 0 );
            while( LL flow = dfs(S, T) ) 
                total += flow;
        }
        return total;
    }
    void clear() {
        for( edge &i: E ) {
            i.flow = 0;
        }
    }
};

void solve() {
    int n, m, temp;
    cin >> n >> m;
    dinic flow(n+m+2);
    for( int i = 1; i <= n; i++ ) {
        cin >> temp;
        flow.add_edge( 0, i, temp );
    }
    for( int i = 1; i <= m; i++ ) {
        cin >> temp;
        flow.add_edge( n+i, n+m+1, temp );
    }
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m ; j++ ) {
            flow.add_edge( i, n+j, 1 );
        }
    }
    LL ans = flow.max_flow( 0, n+m+1 );
    for( int i = 0; i < n; i++ ) {
        if( flow.E[2*i].cap != flow.E[2*i].flow ) {
            cout << " impossible\n";
            return;
        }
    }
    for( int i = 0; i < m; i++ ) {
        if( flow.E[2*(i+n)].cap != flow.E[2*(i+n)].flow ) {
            cout << " impossible\n";
            return;
        }
    }
    cout << '\n';
    /*for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cout << flow.E[2*(i*m+n+m+j)].flow << (j+1==m? '\n' : ' ');
        }
    }*/
    //cout << "Hello\n";
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            int left = 2*i, mid = 2*(n+m+i*m+j), right = 2*(j+n);
            if( flow.E[mid].flow == 1 ) {
                flow.E[mid].cap = 0;
                flow.E[mid^1].cap = 0;
                flow.E[mid].flow = 0;
                flow.E[mid^1].flow = 0;
                flow.E[left].flow -= 1;
                flow.E[left^1].flow += 1;
                flow.E[right].flow -= 1;
                flow.E[right^1].flow += 1;
                if( flow.max_flow(0, n+m+1) ) {
                    cout << '0';
                } else {
                    flow.E[left].flow += 1;
                    flow.E[left^1].flow -= 1;
                    flow.E[right].flow += 1;
                    flow.E[right^1].flow -= 1;
                    cout << '1';
                }
            } else {
                cout << '0';
            }
            flow.E[mid].cap = 0;
            flow.E[mid^1].cap = 0;
            flow.E[mid].flow = 0;
            flow.E[mid^1].flow = 0;
            if( j+1 == m ) 
                cout << '\n';
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":";
        solve();
    }
    return 0;
}