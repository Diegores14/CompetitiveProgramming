#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
const int tam = 1e5+10;
int up[tam][18], mmin[tam][18], mmax[tam][18];
int tin[tam], tout[tam];
int timer = 0;
list< ii > g[tam];

void dfs( int idx, int p, int value = 0 ) {
    tin[idx] = timer++;
    up[idx][0] = p;
    if( idx == 0 )
        mmin[idx][0] = 1e6;
    else {
        mmin[idx][0] = value;
    }
    mmax[idx][0] = value;
    //cout << up[idx][0] << ' ' << mmin[idx][0] << ' ' << mmax[idx][0] << '\n';
    for( int i = 1; i < 18; i++ ) {
        up[idx][i] = up[up[idx][i-1]][i-1];
        mmin[idx][i] = min( mmin[idx][i-1], mmin[up[idx][i-1]][i-1] );
        mmax[idx][i] = max( mmax[idx][i-1], mmax[up[idx][i-1]][i-1] );
        //cout << up[idx][i] << ' ' << mmin[idx][i] << ' ' << mmax[idx][i] << '\n';
    }
    for( ii k: g[idx] ) {
        if( k.first != p ) {
            dfs( k.first, idx, k.second );
        }
    }
    tout[idx] = timer++;
}

bool isAncestor( int u, int v ) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int solveMin( int u , int v ) {
    if( isAncestor( u, v ) ) return 1e6;
    int ans = 1e6;
    for( int i = 17; i >= 0; i-- ) {
        if( !isAncestor( up[u][i], v ) ) {
            ans = min( ans, mmin[u][i] );
            u = up[u][i];
        }
    }
    return min( ans, mmin[u][0] );
}

int solveMax( int u , int v ) {
    if( isAncestor( u, v ) ) return 0;
    int ans = 0;
    for( int i = 17; i >= 0; i-- ) {
        if( !isAncestor( up[u][i], v ) ) {
            ans = max( ans, mmax[u][i] );
            u = up[u][i];
        }
    }
    return max( ans, mmax[u][0] );
}

void solve() {
    for( int i = 0; i < tam; i++ ) {
        g[i].clear();
    }
    int n, q, u, v, w;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        cin >> u >> v >> w; u--; v--;
        g[u].push_back( ii(v, w) );
        g[v].push_back( ii(u, w) );
    }
    cin >> q;
    dfs( 0, 0 );
    //cout << "Solution\n";
    while( q-- ) {
        cin >> u >> v;u--; v--;
        cout << min( solveMin( u, v ), solveMin( v, u ) ) << ' ' << max( solveMax( u, v ), solveMax( v, u ) ) << '\n';

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