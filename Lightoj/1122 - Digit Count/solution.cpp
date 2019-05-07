#include <bits/stdc++.h>
using namespace std; 
int t, n, m; 
long long dp[15][15];
int v[10];

long long solve(int idx, int ant) {
    if(idx == n) { return 1; }
    long long &ans = dp[idx][ant];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i<m; i++) {
        if(idx == 0) {
            ans += solve(idx+1, v[i]);
        } else {
            if(abs(ant-v[i]) <= 2)
                ans += solve(idx+1, v[i]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> m >> n;
        for(int i=0; i<m; i++) {
            cin >> v[i]; 
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << r << ": " << solve(0, 0) << '\n';
    }
    return 0;
}