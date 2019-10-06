#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL INF = 1000000000000;

struct edge {
    int u, v;
    LL cap, flow;
    edge(){}
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
            for( int k: g[u] ) {
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
};

void solve() {
    int n, m, a, b, c;
    cin >> n >> m;
    dinic flow( n+2 );
    int acc[n+2], l[m];
    memset( acc, 0, sizeof acc );
    int s = 0, t = n+1;
    for( int i = 0; i < m; i++ ) {
        cin >> a >> b >> l[i] >> c;
        acc[a] -= l[i];
        acc[b] += l[i];
        flow.add_edge( a, b, c - l[i] );
    }
    LL sum = 0;
    for( int i = 1; i <= n; i++ ) {
        if( acc[i] > 0 ) {
            flow.add_edge( s, i, acc[i] );
            sum += acc[i];
        }
        if( acc[i] < 0 )
            flow.add_edge( i, t, -acc[i] );
    }
    flow.add_edge( n, 1, INF );
    if( sum == flow.max_flow(s, t) ) {
        cout << "yes\n";
        for( int i = 0; i < m; i++ ) {
            cout << flow.E[2*i].flow+l[i] << '\n';
        }
    } else {
        cout << "no\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}