#include <bits/stdc++.h>
using namespace std;
const int mod = 10056;
int combinatoric[1005][1005];
int dp[1005];

void precalculo() {
    for(int i = 0; i <= 1000; i++) {
        combinatoric[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            combinatoric[i][j] = (combinatoric[i-1][j] + combinatoric[i-1][j-1]) % mod;
        }
    }
}

int solve(int n) {
    if(n == 0) return 1;
    int &ans = dp[n];
    if(ans != -1) {
        return ans;
    }
    ans = 0;
    for(int k = 1; k <= n; k++) {
        ans = (ans + combinatoric[n][k] * solve(n-k)) % mod;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(combinatoric, 0, sizeof combinatoric);
    precalculo();
    memset(dp, -1, sizeof dp);
    int t, n;
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n; 
        cout << "Case " << cases << ": " << solve(n) << '\n';
    }
    return 0;
}