#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge {
    int u, v;
    LL cap, flow;
    edge() {}
    edge( int u, int v, int cap): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
    int N;
    vector< edge > E;
    vector< vector < int > > g;
    vector< int > d, pt;
    dinic( int N ): N(N), E(0), g(N), d(N), pt(N) {}
    void add_edge( int  u, int v, LL cap ) {
        if( u != v ) {
            E.push_back( edge(u, v, cap) );
            g[u].push_back( E.size() -1 );
            E.push_back( edge(v, u, 0) );
            g[v].push_back( E.size() -1 );
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
                if( e.flow < e.cap && d[e.v] > d[e.u] + 1 )  {
                    d[e.v] = d[e.u] + 1;
                    q.push( e.v );
                }
            }
        }
        return d[T] != N + 1;
    }
    LL dfs( int u, int T, LL flow = -1 ) {
        if( u == T || flow == 0 ) return flow;
        for( int &i = pt[u]; i < int(g[u].size()); ++i ) {
            edge &e = E[g[u][i]];
            edge &oe = E[g[u][i]^1];
            if( d[e.v] == d[e.u]+1 ) {
                LL amt = e.cap - e.flow;
                if( flow != -1 && amt > flow ) amt = flow;
                if( LL pushed = dfs(e.v, T, amt ) ) {
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
    int n, m, temp;
    cin >> n >> m;
    dinic flow(2*(n+m)+2);
    int s = 2*(n+m), t = s+1;
    int len = 0;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            //cout << i+j << ' ' << i-j+2*m+n-2 << '\n';
            flow.add_edge( i+j, i-j+2*m+n-2, 99 );
        }
    }
    //cout << "First\n";
    for( int i = 0; i < n+m-1; i++ ) {
        cin >> temp;
        if( i < min(n, m) ) {
            len++;
        } else {
            len = min( min(n, m), n+m-i-1 );
        }
        //cout << s << ' '  << i << ' ' << temp-len << '\n';
        flow.add_edge( s, i, temp-len );
    }
    //cout << "First\n";
    len = 0;
    for( int i = 0; i < n+m-1; i++ ) {
        cin >> temp;
        if( i < min(n, m) ) {
            len++;
        } else {
            len = min( min(n, m), n+m-i-1 );
        }
        //cout << n+m-1+i << ' '  << t << ' ' << temp-len << '\n';
        flow.add_edge( n+m-1+i, t, temp-len );
    }
    flow.max_flow( s, t );
    len = 0;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cout << flow.E[len].flow+1 << ( j+1 == m? '\n' : ' ' );
            len += 2;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":\n";
        solve();
    }
    return 0;
}