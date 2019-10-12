#include <bits/stdc++.h>
using namespace std;

struct MCMF {
    typedef int ctype;
    enum { MAXN = 1000, INF = INT_MAX };
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
        flowVal = flowCost = 0; memset( phi, 0, sizeof(phi) );
        while( true ) {
            for( x = 0; x < N; x++ ) prev[x] = -1;
            for( x = 0; x < N; x++ ) dist[x] = INF;
            set< pair< ctype, int > > Q;
            dist[s] = prev[s] = 0;
            Q.insert( make_pair( dist[s], s) );
            while( !Q.empty() ) {
                x = Q.begin()->second; Q.erase( Q.begin() );
                for( int it: adj[x] ) {
                    const Edge &e = E[it];
                    if( e.cap <= 0 ) continue;
                    ctype cc = e.cost + phi[x] - phi[e.y];
                    if( dist[x] + cc < dist[e.y] ) {
                        Q.erase( make_pair(dist[e.y], e.y) );
                        dist[e.y] = cc + dist[x];
                        prev[e.y] = it;
                        Q.insert( make_pair(dist[e.y], e.y) );
                    }
                }
            }
            if( prev[t] == -1 ) break;
            ctype z = INF;
            for( x = t; x != s; x = E[prev[x]].x ) {
                z = min( z, E[prev[x]].cap );
            }
            for( x = t; x != s; x = E[prev[x]].x ) {
                E[prev[x]].cap -= z; E[prev[x]^1].cap += z;
            }
            flowVal += z;
            flowCost += z*( dist[t] - dist[s] + phi[t] );
            for( x = 0; x < N; x++ ) {
                if( prev[x] != -1 ) prev[x] += dist[x];
            }
        }
    }
};

bool used[101][101];
typedef pair< int, int > ii;
int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};
map< ii, int > position;
struct node { int x, y, cant; node(int x, int y, int cant): x(x), y(y), cant(cant) {} };
string v[101];

void BFS( int x, int y, int n, int pos, MCMF &f ) {
    queue< node > Q;
    Q.push( node(x, y, 0) );
    used[x][y] = true;
    while( !Q.empty() ) {
        node temp = Q.front(); Q.pop();
        if( v[temp.x][temp.y] == 'm' ) {
            f.add( pos, position[ii(temp.x, temp.y)], 1, temp.cant );
        }
        for( int i = 0; i < 4; i++ ) {
            int tempx = temp.x + dx[i];
            int tempy = temp.y + dy[i];
            if( 0 <= tempx && tempx < n  && 0 <= tempy && tempy < n && 
                !used[tempx][tempy] && v[tempx][tempy] != '#') {
                    used[tempx][tempy] = true;
                    Q.push( node(tempx, tempy, temp.cant+1) );
            }
        }
    }
}

void solve() {
    position.clear();
    int n, k, m;
    cin >> n >> k >> m;
    int values[k];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    for( int i = 0; i < k; i++ ) {
        cin >> values[i];
    }
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( v[i][j] == 'm' ) {
                position[ ii(i, j) ] = position.size()+k+1;
            }
        }
    }
    MCMF f( k+m+2 );
    int t = k+m+1;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( v[i][j] != '.' && v[i][j] != '#' && v[i][j] != 'm') {
                memset( used, 0, sizeof used);
                BFS( i, j, n, v[i][j]-'A'+1, f );
            }
        }
    }
    for( int i = 1; i <= k; i++ ) {
        f.add( 0, i, values[i-1], 0);
    }
    for( int i = 0; i < m; i++ ) {
        f.add( k+1+i, t, 1, 0 );
    }
    int flow, cost; 
    f.mcmf( 0, t, flow, cost );
    cout << cost << '\n';
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
