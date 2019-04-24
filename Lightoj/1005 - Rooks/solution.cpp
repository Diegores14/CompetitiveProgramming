#include <bits/stdc++.h>
using namespace std;
long long dp[35][905];


int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        cout << "Case " << cas << ": ";
        memset(dp, 0, sizeof dp);
        cin >> n >> k;
        dp[n][k] = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j>=0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i+1][j+1] * (n-j);
            }
        }
        cout << dp[0][0] << '\n';
    }
    return 0;
}