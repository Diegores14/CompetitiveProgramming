#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
const int tam = 1e6+10;
int dp[tam];
int INF = 1000000000;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    fill(dp, dp+tam, INF);
    cin >> n >> x;
    dp[0] = 0;
    int coin[n];
    for( int i = 0; i < n; i++  ) {
        cin >> coin[i];
    }
    for( int i = 1; i <= x; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( 0 <= i-coin[j] ) {
                dp[i] = min(dp[i], 1+dp[i-coin[j]]);
            }
        }
    }
    if( dp[x] == INF)
        cout << -1 << '\n';
    else 
        cout << dp[x] << '\n';
    return 0;
}
