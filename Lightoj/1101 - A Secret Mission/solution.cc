#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef pair< int, int > ii;
const int tam = 50005, tam1 = 18;
list< ii > G[tam];
int p[tam], in[tam], out[tam], up[tam][tam1], dp[tam][tam1], timer;

int findSet( int i ) { return (p[i] == i)? i : p[i] = findSet(p[i]); }
bool sameSet( int i, int j ) { return findSet(i) == findSet(j); }

int unionSet( int i, int j ) {
    int x = findSet(i), y = findSet(j);
    if(  x != y ) {
        p[x] = y;
    }
}

struct node {
    int x, y, cost;
    node(){}
    bool operator <( node other ) const {
        return cost < other.cost;
    }
}v[tam*10];

void MST() {
    sort( v, v+m );
    for( int i = 0; i < m; i++ ) {
        int x = v[i].x;
        int y = v[i].y;
        int cost = v[i].cost;
        if( !sameSet( x, y ) ) {
            unionSet( x, y );
            G[x].push_back( ii(y, cost) );
            G[y].push_back( ii(x, cost) );
        }
    }
}

void DFS( int idx, int p, int cost ) {
    in[idx] = timer++;
    up[idx][0] = p; dp[idx][0] = cost;
    for( int i = 1; i < tam1; i++ ) {
        up[idx][i] = up[ up[idx][i-1] ][i-1];
        dp[idx][i] = max( dp[ up[idx][i-1] ][i-1], dp[idx][i-1] );
    }
    for( ii &i: G[idx] ) {
        if( i.first == p ) continue;
        DFS( i.first, idx, i.second );
    }
    out[idx] = timer++;
}

bool isAncestor( int u, int v ) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int answer( int u, int v ) {
    if( isAncestor(u, v) ) 
        return 0;
    int ans = 0;
    for( int l = tam1-1; l >= 0; l-- ) {
        if( !isAncestor( up[u][l], v ) ) {
            ans = max( ans, dp[u][l] );
            u = up[u][l];
        }
    }
    return max( ans, dp[u][0] );
}

void solve() {
    cin >> n >> m;
    timer = 0;
    for( int i = 0; i <= n; i++ ) {
        G[i].clear();
        p[i] = i;
        for( int j  = 0; j < tam1; j++ ) {
            up[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    in[0] = -1; out[0] = 10000000;
    for( int i = 0; i < m; i++ ) {
        cin >> v[i].x >> v[i].y >> v[i].cost;
    }
    MST();
    DFS( 1, 0, 0 );
    int q, a, b;
    cin >> q;
    while( q-- ) {
        cin >> a >> b;
        cout << max( answer( a, b ), answer( b, a ) ) << '\n';
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