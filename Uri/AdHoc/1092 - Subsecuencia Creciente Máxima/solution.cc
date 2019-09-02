#include <bits/stdc++.h>
using namespace std;
const int tam = 605;
int v[tam][tam];
int dp1[tam][tam];
int dp[2][tam][tam];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    while( cin >> n >> m, n || m ) {
        memset( dp, 0, sizeof dp );
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                cin >> v[i][j];
                dp1[i][j] = 1;
                if(j != 0  && v[i][j-1] < v[i][j] )
                    dp1[i][j] += dp1[i][j-1];
            }
        }
        int cur = 0;
        int ans = 1;
        for( int i = n-1; i >= 0; i-- ) {
            for(int j = 0; j < m; j++ ) {
                for( int k = dp1[i][j]; k > 0; k-- ) {
                    dp[cur][j][k] = k;
                    if( i != n-1 && v[i+1][j-k+1] > v[i][j] ) {
                        dp[cur][j][k] += dp[cur^1][j][k];
                    }
                    ans = max(ans, dp[cur][j][k] );
                }
            }
            cur ^= 1;
            memset(dp[cur], 0, sizeof dp[cur] );
        }
        cout << ans << '\n';
    }
    return 0;
}