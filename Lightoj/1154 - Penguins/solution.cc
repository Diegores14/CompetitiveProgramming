#include <bits/stdc++.h>
using namespace std;
int const tam = 105;
typedef long long LL;
typedef pair< int, int> ii;
int in[tam], out[tam];
long long x[tam], y[tam], n[tam], m[tam];
int len = 0;

struct edge {
    int u, v;
    LL cap, flow;
    edge() {}
    edge( int u, int v, LL cap ): u(u), v(v), cap(cap), flow(0) {}
};

struct dinic {
    int N;
    vector< edge > E;
    vector< vector < int > > g;
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
        queue<int> q({S});
        fill( d.begin(), d.end(), N + 1 );
        d[S] = 0;
        while( !q.empty() ) {
            int u = q.front(); q.pop();
            if( u == T ) break;
            for( int k: g[u] ) {
                edge &e = E[k];
                if( e.flow < e.cap && d[e.v] > d[e.u] + 1 ) {
                    d[ e.v ] = d[ e.u ] + 1;
                    q.push(e.v);
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
            if( d[e.v] == d[e.u] + 1 ) {
                LL amt = e.cap - e.flow;
                if( flow != -1 && amt > flow ) amt = flow;
                if( LL pushed = dfs(e.v, T, amt) ) {
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
            fill(pt.begin(), pt.end(), 0);
            while( LL flow = dfs(S, T) ) {
                total += flow;
            }
        }
        return total;
    }
};

long double dist(int i, int j) {
    return sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    long double D;
    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++ ) {
        cin >> N >> D;
        int sum = 0;
        len = 1;
        for( int i = 0; i < N; i++ ) {
            in[i] = len++;
        }
        for( int i = 0; i < N; i++ ) {
            out[i] = len++;
        }
        vector< ii > v;
        for( int i = 0; i < N; i++ ) {
            cin >> x[i] >> y[i] >> n[i] >> m[i];
            sum += n[i];
            for( int j = 0; j < i; j++ ) {
                if( dist(i, j) <= D ) {
                    v.push_back( ii(i, j) );
                    v.push_back( ii(j, i) );
                }
            }
        }
        vector< int > ans;
        for( int i = 0; i < N; i++ ) {
            dinic din(len);
            for(int j = 0; j < N; j++) {
                din.add_edge( in[j], out[j], m[j] );
                din.add_edge( 0, in[j], n[j] );
            }
            for( ii &j: v ) {
                din.add_edge( out[j.first], in[j.second], 10000000 );
            }
            long long aux = din.max_flow(0, in[i]);
            //cout << aux << '\n';
            if( sum ==  aux)
                ans.push_back(i);
        }
        cout << "Case " << cases << ": ";
        if( ans.size() ) {
            for( int i = 0; i < ans.size(); i++ ) {
                cout << ans[i] << ((i+1 == ans.size())? '\n' : ' ');
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}