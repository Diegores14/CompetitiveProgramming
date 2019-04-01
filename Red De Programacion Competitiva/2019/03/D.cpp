#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 9;

int dp[130][1005][130];
int k, b;

int exponentation(int b, int e) {
    int ans = 1;
    while(e) {
        if(e&1) {
            ans = (ans * b) % k;
        }
        b = (b*b) % k;
        e >>= 1;
    }
    return ans % k;
}

int solve(int idx, int acc, int bits) {
    if(idx == -1) {
        return acc? 0 : bits;
    }
    int & ans = dp[idx][acc][bits];
    if(ans != -1) {
        return ans;
    }
    ans = (solve(idx-1, (exponentation(2, idx) + acc)%k, bits + 1) + 
            solve(idx-1, acc, bits)) % mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> b;
    memset(dp, -1, sizeof dp);
    cout << solve(b-1, 0, 0) << '\n';
    return 0;
}