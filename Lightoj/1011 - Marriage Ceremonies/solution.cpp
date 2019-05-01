#include <bits/stdc++.h>
using namespace std;
int dp[17][(1<<17)];
int v[17][17];
int t, n;

int solve(int idx, int mask) {
    if(idx == n) return 0;
    int &ans = dp[idx][mask];
    if(ans != -1) return ans;
    for(int i=0; i<n; i++) {
        if(((mask>>i)&1) == 0) {
            ans = max(ans, solve(idx+1, mask|(1<<i)) + v[idx][i]);
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stidio(false); cin.tie(NULL);
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        for(int i=0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << '\n';
    }
    return 0;
}