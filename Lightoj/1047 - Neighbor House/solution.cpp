#include <bits/stdc++.h>
using namespace std;
typedef vector< int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    map< int, ii> m;
    m[0] = { 1, 2 };
    m[1] = { 0, 2 };
    m[2] = { 0, 1 };
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n;
        int dp[n+1][3], v[3];
        for(int i = 0; i <= n; i++) {
            for(int j=0; j < 3; j++) {
                dp[i][j] = i? 1000000000 : 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            cin >> v[0] >> v[1] >> v[2];
            for(int j=0; j < 3; j++) {
                for(int k: m[j]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + v[j]);
                }
            }
        }
        int ans = 1000000000;
        for(int i = 0; i < 3; i++) {
            ans = min(ans, dp[n][i]);
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}