#include <bits/stdc++.h>
using namespace std;
int n;
long double dp[21][1<<20];
long long v[20][20];

long double solve(int idx, int mask) {
    if(idx == n) {
        return 1;
    }
    long double &ans = dp[idx][mask];
    if(ans != -1) { return ans; }
    for(int i = 0; i < n; i++) {
        if((mask&(1<<i)) == 0) {
            ans = max(ans, (solve(idx+1, mask|(1<<i)) * v[idx][i])/100);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j = 0; j < (1<<20); j++) {
            dp[i][j] = -1;
        }
    }
    cout << fixed << setprecision(10) << solve(0, 0) * 100 << '\n';
    return 0;
}