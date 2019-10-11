#include <bits/stdc++.h>
using namespace std;
const int tam = 102;
int dp[tam][tam][tam];

void solve() {
    int n, m;
    cin >> n >> m;
    int v[n+1][m+1];
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            cin >> v[i][j];
        }
    }
    for( int i = 1; i <= n; i++ ) {
        for( int k = 2; k <= m; k++ ) {
            for( int j = 1; j < k; j++ ) {
                dp[i][j][k] = dp[i-1][j][k] + v[i][j] + v[i][k];
            }
        }
        for( int j = 2; j < m; j++ ) {
            for( int k = j+1; k <= m; k++ ) {
                dp[i][j][k] = max( dp[i][j][k], dp[i][j-1][k] + v[i][j] );
            }
        }
        for( int j = 1; j < m; j++ ) {
            for( int k = j+2; k <= m; k++ ) {
                dp[i][j][k] = max( dp[i][j][k], dp[i][j][k-1] + v[i][k] );
            }
        }
    }
    cout << dp[n][m-1][m] << '\n';
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