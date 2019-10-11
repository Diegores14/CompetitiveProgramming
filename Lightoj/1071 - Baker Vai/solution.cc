#include <bits/stdc++.h>
using namespace std;

struct MCMF {
    typedef int ctype;
    enum { MAXN = 20000, INF = INT_MAX };
    struct Edge { int x, y; ctype cap, cost; };
    vector< Edge > E; vector< int > adj[MAXN];
    int N, prev[MAXN]; ctype dist[MAXN], phi[MAXN];
    MCMF( int NN ): N(NN) {}
    void add( int x, int y, ctype cap, ctype cost ) {
        Edge e1 = {x,y,cap,cost}, e2 = {y,x,0,-cost};
        adj[e1.x].push_back( E.size() ); E.push_back( e1 );
        adj[e2.x].push_back( E.size() ); E.push_back( e2 );
    }
    void mcmf( int s, int t, ctype &flowVal, ctype &flowCost ) {
        int x;
        flowVal = flowCost = 0; memset( phi, 0, sizeof phi );
        while( true ) {
            for( x = 0; x < N; x++ ) prev[x] = -1;
            for( x = 0; x < N; x++ ) dist[x] = INF;
            dist[s] = prev[s] = 0;
            set< pair< ctype, int > > Q;
            Q.insert( make_pair(dist[s], s) );
            while( !Q.empty() ) {
                x = Q.begin()->second; Q.erase(Q.begin());
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
                z = min(z, E[prev[x]].cap );
            }
            for( x = t; x != s; x = E[prev[x]].x ) {
                E[prev[x]].cap -= z; E[prev[x]^1].cap += z;
            }
            flowVal += z;
            flowCost += z*( dist[t] - phi[s] + phi[t] );
            for( x = 0; x < N; x++ ) {
                if( prev[x] != -1 ) phi[x] += dist[x];
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    MCMF flow( 2*n*m );
    int v[n][m];
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cin >> v[i][j];
            if( (j == 0 && i == 0) || (j+1 == m && i+1 == n) ) {
                //cout << i << ' ' << j << '\n';
                flow.add( (2*(i*m+j)), (2*(i*m+j))^1, 2, -v[i][j] );
            } else {
                flow.add( (2*(i*m+j)), (2*(i*m+j))^1, 1, -v[i][j] );
            }
            if( j+1 != m ) {
                flow.add( (2*(i*m+j))^1, 2*(i*m+j+1), 1, 0 );
            }
            if( i+1 != n ) {
                flow.add( (2*(i*m+j))^1, 2*(i*m+j+m), 1, 0 );
            }
        }
    }
    int flowVal, cost;
    flow.mcmf(0, (2*n*m-1), flowVal, cost );
    cout << -cost -v[0][0] - v[n-1][m-1] << '\n';
}

/*
1
3 3
0 2 2 
1 3 0 
1 3 1 
| 0 -2 -2
| -1 -3 0
| -1 -3 -1
 */

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