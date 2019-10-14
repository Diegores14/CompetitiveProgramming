#include <bits/stdc++.h>
using namespace std;
const int tam = 16;
const int len = (1<<tam);
list< int > G[tam];
double dp[tam][len];

struct edge {
    int u, v, w;
    edge( int u, int v, int w ): u(u), v(v), w(w) {}
};

vector< edge > E;

double DFS( int idx, int bits, const int &limit ) {
    if( limit == bits ) return 0;
    if( dp[idx][bits] != -2 ) return dp[idx][bits];
    dp[idx][bits] = -1;
    double sum = 0;
    int cnt = 0;
    for( int to: G[idx] ) {
        edge e = E[to];
        if( ((bits>>e.v)&1) == 0 ) {
            double ans = DFS( e.v, bits|(1<<e.v), limit );
            if( ans != -1 ){
                sum += e.w+ans;
                cnt++;
            }
        }
    }
    if( cnt ) {
        dp[idx][bits] = (sum+5)/cnt;
    } 
    return dp[idx][bits];
}

void solve() {
    int n, m, u, v, w;
    for( int i = 0; i < tam; i++ ) G[i].clear();
    for( int i = 0; i < tam; i++ ) {
        for( int j = 0; j < len; j++ ) {
            dp[i][j] = -2;
        }
    }
    E.clear();
    cin >> n >> m;
    for( int i = 0; i < m; i++ ) {
        cin >> u >> v >> w;
        G[u].push_back( E.size() );
        E.push_back( edge(u, v, w) );
        G[v].push_back( E.size() );
        E.push_back( edge(v, u, w) );
    }
    double ans = DFS( 0, 1, (1<<n) - 1 );
    if( ans == -1 ) {
        ans = 0;
    } 
    cout << ans << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}