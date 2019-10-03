#include <bits/stdc++.h>
using namespace std;
const int tam = 110;
int n, d;

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
            E.push_back( edge(u, v, cap ) );
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
            for( int k : g[u] ) {
                edge &e = E[k];
                if( e.flow < e.cap && d[e.v] > d[e.u] + 1 ) {
                    d[e.v] = d[e.u] + 1;
                    q.push(e.v);
                }
            }
        }
        return d[T] != N+1;
    }
    LL dfs( int u, int T, LL flow = -1 ) {
        if( u == T || flow == 0 ) return flow;
        for( int &i = pt[u]; i < int(g[u].size()); ++i ) {
            edge &e = E[g[u][i]];
            edge &oe = E[g[u][i]^1];
            if( d[e.v] == d[e.u] + 1 ) {
                LL amt = e.cap - e.flow;
                if( flow != -1 && amt > flow) amt = flow;
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

struct node {
    bool typ;
    int x;
    node() {}
    node( bool typ, int x ): typ(typ), x(x) {}
}v[tam];

bool f( long long mid ) {
    dinic di(2*n);
    for( int i = 0; i < n; i++ ) {
        if( v[i].typ ) {
            di.add_edge( (i*2), (i*2)^1, 2 );
        } else {
            di.add_edge( (i*2), (i*2)^1, 1 );
        }
        for( int j = 0; j < i; j++) {
            if( v[i].x - v[j].x <= mid ) {
                di.add_edge( (j*2)^1, i*2, 2 );
            }
        }
    }
    return di.max_flow( 0, 2*n-1 ) > 1;
}

void solve() {
    char c, o;
    cin >> n >> d;
    n += 2;
    v[0] = node( true, 0 );
    v[n-1] = node( true, d );
    for( int i = 1; i < n-1; i++ ) {
        cin >> c >> o >> v[i].x;
        v[i].typ = (c == 'B' );
    }
    long long l = 0, r = d;
    while( r - l != 1 ) {
        int mid = (l+r)/2;
        if( f(mid) ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
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