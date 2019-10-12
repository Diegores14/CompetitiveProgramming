#include <bits/stdc++.h>
using namespace std;

struct MCMF {
    typedef long long ctype;
    enum { MAXN = 1000, INF = INT_MAX };
    struct Edge { int x, y; ctype cap, cost; };
    vector< Edge > E; vector< int > adj[MAXN];
    int N, prev[MAXN]; ctype dist[ MAXN ], phi[ MAXN ];
    MCMF( int NN ): N(NN){}
    void add ( int x, int y, ctype cap, ctype cost ) {
        Edge e1 = {x,y,cap,cost}, e2 = {y,x,0,-cost};
        adj[e1.x].push_back( E.size() ); E.push_back( e1 );
        adj[e2.x].push_back( E.size() ); E.push_back( e2 );
    }
    void mcmf( int s, int t, ctype &flowVal, ctype &flowCost ) {
        int x;
        flowVal = flowCost = 0;  memset( phi, 0, sizeof(phi) );
        while( true ) {
            for( x = 0; x < N; x++ ) prev[x] = -1;
            for( x = 0; x < N; x++ ) dist[x] = INF;
            dist[s] = prev[s] = 0;
            set< pair< ctype, int > > Q;
            Q.insert( make_pair(dist[s], s) );
            while( !Q.empty() ) {
                x = Q.begin()->second; Q.erase( Q.begin() );
                for( int it: adj[x] ) {
                    const Edge &e = E[it];
                    if( e.cap <= 0 ) continue;
                    ctype cc = e.cost + phi[x] - phi[e.y];
                    if( dist[x] + cc < dist[e.y] ) {
                        Q.erase( make_pair(dist[e.y], e.y) );
                        dist[e.y] = dist[x] + cc;
                        prev[e.y] = it;
                        Q.insert( make_pair(dist[e.y], e.y) );
                    }
                }
            }
            if( prev[t] == -1 ) break;
            ctype z = INF;
            for( x = t; x != s; x = E[prev[x]].x ) {
                z = min(z, E[prev[x]].cap);
            }
            for( x = t; x != s; x = E[prev[x]].x ) {
                E[prev[x]].cap -= z; E[prev[x]^1].cap += z;
            }
            flowVal += z;
            flowCost += z*(dist[t] - phi[s] + phi[t] );
            for( x = 0; x < N; x++ ) {
                if( prev[x] != -1 ) phi[x] += dist[x];
            }
        }
    }
};

void solve() {
    long long n, k, g;
    cin >> n >> k >> g;
    int v[2][n]; 
    for( int i = 0; i < 2; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin >> v[i][j];
        }
    }
    MCMF f( 2*n+2 ), f1( 2*n+2 );
    int s = 2*n, t = s+1;
    for( int i = 0; i < n; i++ ) {
        f.add( s, 2*i, 1, 0 );
        f.add( (2*i)^1, t, 1, 0 );
        f1.add( s, 2*i, 1, 0 );
        f1.add( (2*i)^1, t, 1, 0 );
        for( int j = 0; j < n; j++ ) {
            if( v[0][i] < v[1][j] ) {
                long long t = v[1][j] - v[0][i];
                long long temp = min( g, (t-k)*(t-k) );
                //cout << 2*i << ' ' << ((2*j)^1) << ' ' << t << '\n';
                f.add( 2*i, (2*j)^1, 1, temp);
                f1.add( 2*i, (2*j)^1, 1, -temp);
            }
        }
    }
    long long flow, cost1, cost2;
    f.mcmf( s, t, flow, cost1 );
    if( flow == n ) {
        f1.mcmf(s, t, flow, cost2 );
        cout << cost1 << ' ' << -cost2 << '\n';
    } else {
        cout << "impossible\n";
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