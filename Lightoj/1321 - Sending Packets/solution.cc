#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v;
    double cap;
    edge(){}
    edge( int u, int v, double cap ): u(u), v(v), cap(cap) {}
};
list< int > G[101];
vector< edge > E;
typedef pair< double, int > di;

double disjktra( int n ) {
    priority_queue< di > Q;
    double dist[n];
    memset( dist, 0, sizeof dist );
    dist[0] = 1;
    Q.push( di(dist[0], 0) );
    while( !Q.empty() ) {
        int x = Q.top().second; 
        double p = Q.top().first; Q.pop();
        if( p != dist[x] ) continue;
        if( x == n-1 ) break;
        for( int it: G[x] ) {
            edge e = E[it];
            if( dist[e.v] < dist[e.u]*e.cap ) {
                dist[e.v] = dist[e.u]*e.cap;
                Q.push( di(dist[e.v], e.v) );
            }
        }
    }
    return dist[n-1];
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m, s, k, u, v;
    double p;
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n >> m >> s >> k;
        for( int i = 0; i < n; i++ ) G[i].clear();
        for( int i = 0; i < m; i++ ) {
            cin >> u >> v >> p; 
            G[u].push_back( E.size() );
            E.push_back( edge(u, v, p/100));
            G[v].push_back( E.size() );
            E.push_back( edge(v, u, p/100));
        }
        p = disjktra( n );
        cout << "Case " << cases << ": " << ((1-p)/p+1)*s*2*k << '\n';
    }
    return 0;
}