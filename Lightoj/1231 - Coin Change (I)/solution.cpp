#include <bits/stdc++.h>
using namespace std;
int v[51], c[51];
long long dp[1005][50];
int n, k;
int mod = 100000007;

long long solve(int idx, int acc) {
    if(acc == k) return 1;
    if(idx == n || acc > k) return 0;
    long long &ans = dp[acc][idx];
    if(ans != -1) return ans;
    ans = 0;
    for(int i=0; i <= c[idx]; i++) {
        ans = (ans + solve(idx + 1, acc + v[idx] * i) )%mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int r=1; r<=t; r++) {
        cout << "Case " << r << ": ";
        cin >> n >> k;
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        for(int i=0; i<n; i++) {
            cin >> c[i];
        }
        cout << solve(0, 0) << '\n';
    }
    return 0;
}