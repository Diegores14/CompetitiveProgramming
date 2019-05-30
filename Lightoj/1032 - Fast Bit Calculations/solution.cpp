#include <bits/stdc++.h>
using namespace std;
long long dp[33][2][2][32];

long long solve(int idx, long long top, bool isTop, bool isOne, int cant) {
    if(idx == -1)  return cant;
    long long &ans = dp[idx][isTop][isOne][cant];
    if(ans != -1) return ans;
    ans = 0;
    int limit = isTop? ((top>>idx)&1) : 1;
    for(int i = 0; i <= limit; i++) {
        ans = ans + solve(idx-1, top, (isTop && (limit == i)), i, cant + (isOne && i != 0)) ;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t, n;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cout << "Case " << cases << ": ";
        memset(dp, -1, sizeof dp);
        cin >> n;
        cout << solve(32, n, true, false, 0) << '\n';
    }
    return 0;
}