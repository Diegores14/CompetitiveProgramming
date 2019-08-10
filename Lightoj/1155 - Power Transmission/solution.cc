#include <bits/stdc++.h>
using namespace std;
const int tam = 105;
int in[tam], out[tam];

typedef long long LL;

struct edge {
    int u, v;
    LL cap, flow;
    edge() {}
    edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
    int N;
    vector< edge > E;
    vector< vector< int > > g;
    vector< int > d, pt;
    dinic( int N ): N(N), E(0), g(N), d(N), pt(N)  {}
    void add_edge(int u, int v, LL cap) {
        if( u != v ){
            E.push_back(edge(u, v, cap));
            g[u].push_back(E.size()-1);
            E.push_back(edge(v, u, 0));
            g[v].push_back(E.size()-1);
        }
    }
    bool bfs(int S, int T) {
        queue< int > q({S});
        fill(d.begin(), d.end(), N+1);
        d[S] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if( u == T ) break;
            for( int k: g[u] ) {
                edge &e = E[k];
                if( e.flow < e.cap && d[e.v] > d[e.u] + 1) {
                    d[e.v] = d[e.u] + 1;
                    q.push( e.v );
                }
            }
        }
        return d[T] != N+1;
    }
    LL dfs(int u, int T, LL flow = -1) {
        if( u == T || flow == 0) return flow;
        for( int i = pt[u]; i < int(g[u].size()); i++ ) {
            edge &e = E[g[u][i]];
            edge &oe = E[g[u][i]^1];
            if( d[e.v] == d[e.u] + 1 ) {
                LL amt = e.cap - e.flow;
                if(flow != -1 && flow < amt) amt = flow;
                if(LL pushed = dfs(e.v, T, amt) ) {
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
            while( LL flow = dfs(S, T) ) {
                total += flow;
            }
        }
        return total;
    }
};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, a, b, d, cost;
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n;
        int len = 1;
        for(int i = 1; i <= n; i++) {
            in[i] = len++;
        }
        for(int i = 1; i <= n; i++) {
            out[i] = len++;
        }
        dinic dic(len+2);
        for(int i = 1; i <= n; i++) {
            cin >> cost;
            dic.add_edge(in[i], out[i], cost);
        }
        cin >> m;
        for( int i = 0; i < m; i++ ) {
            cin >> a >> b >> cost;
            dic.add_edge( out[a], in[b], cost );
        }
        cin >> b >> d;
        for(int i = 0; i < b; i++ ) {
            cin >> a;
            dic.add_edge( 0, in[a], 1000000000 );
        }
        for(int i = 0; i < d; i++ ) {
            cin >> a;
            dic.add_edge( out[a], len+1, 1000000000 );
        }
        //cout << "Hello \n";
        cout << "Case " << cases << ": " << dic.max_flow(0, len+1) << '\n';
    }
    return 0;
}