#include <bits/stdc++.h>
using namespace std;
//long long dp[105][10005];
int ans[2][10005];
int t, n, r, mod = 100000007;
int v[100];
 
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> n >> r;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        sort(v, v + n);
        memset(ans, 0, sizeof ans);
        ans[0][0] = 1;
        //cout << solve(0, 0) << '\n';
        for(int i = 0; i < n; i++) {
            memset(ans[1], 0, sizeof ans[1]);
            for(int j=v[i]; j <= r; j++) {
                ans[1][j] = (ans[0][j-v[i]] + ans[1][j-v[i]]) % mod;
            }
            for(int j = 0; j <= r; j++) {
                ans[0][j] = (ans[0][j] + ans[1][j]) % mod;
            }
        }
        cout << ans[0][r] << '\n';
    }
    return 0;
}