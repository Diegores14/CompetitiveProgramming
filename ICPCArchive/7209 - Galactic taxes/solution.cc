#include <bits/stdc++.h>
using namespace std;
typedef pair< double, int > di;
int n, m;
const int tam = 1005;
list< tuple< int, int, int > > G[tam];
double dist[tam];
bool used[tam];

double cal( tuple< int, int, int > x, double t ) {
    return t*get<0>(x) + get<1>(x);
}

double dijkstra( double x ) {
    for( int i = 0; i <= n; i++ ) dist[i] = 1e18;
    memset( used, 0, sizeof used );
    set< di > q;
    q.insert( di(0, 1) );
    dist[1] = 0;
    while( !q.empty() && q.begin()->second != n ) {
        int cur = q.begin()->second;
        q.erase( q.begin() );
        if( !used[cur] ) {
            used[cur] = true;
            for( auto &i: G[cur] ) {
                int next = get<2>(i);
                double cost = cal( i, x );
                if( !used[next] && dist[next] > dist[cur] + cost ) {
                    q.erase( di(dist[next], next) );
                    dist[next] = dist[cur] + cost;
                    q.insert( di(dist[next], next) );
                }
            }
        }
    }
    return q.begin()->first;
}

void solve() {
    int a, b, x, y;
    for( int i = 1; i <= n; i++ ) G[i].clear();
    for( int i = 0; i < m; i++ ) {
        cin >> x >> y >> a >> b;
        G[x].push_back( make_tuple(a, b, y) );
        G[y].push_back( make_tuple(a, b, x) );
    }
    double l = 0, r = 24*60; 
    // ternary search
    for( int i = 0; i < 100; i++ ) {
        double k1 = l + (r-l)/3;
        double k2 = r - (r-l)/3;
        if( dijkstra(k1) < dijkstra(k2) ) {
            l = k1;
        } else {
            r = k2;
        }
    }
    cout << dijkstra( (l+r)/2 ) << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(5);
    while( cin >> n >> m ) {
        solve();
    }
    return 0;
}