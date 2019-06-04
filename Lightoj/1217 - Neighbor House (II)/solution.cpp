#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1005];
long long dp[1005][2];

long long solve(int idx, int one) {
    if(idx >= n)  return 0;
    if(idx == n-1 && one == 1) return 0;
    long long &ans = dp[idx][one];
    if(ans != -1) return ans;
    ans = solve(idx+1, one);
    if(idx == 0) {
        one = 1;
    }
    ans = max(ans, solve(idx+2, one) + a[idx]);
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << cases << ": " << solve(0, 0) << '\n';
    }
    return 0;
}