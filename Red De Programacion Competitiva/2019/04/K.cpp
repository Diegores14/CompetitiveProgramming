#include <bits/stdc++.h>
using namespace std;
int dp[20][(1<<19)], n;
string s1, s2;

int solve(int idx, int mask) {
    if(idx == n) {
        return 0;
    }
    int &ans = dp[idx][mask];
    if(ans != -1) return ans;
    ans = 1000000000;
    for(int i=0; i<n; i++) {
        int temp = mask;
        for(int j=0; j+i<n; j++) {
            if(((mask >> (i+j)) & 1) == 0 && s1[i+j] == s2[idx+j]) {
                temp |= (1<<(i+j));
                ans = min(ans, solve(idx+j+1, temp) + 1);
            } else {
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s1 >> s2;
    n = s1.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) - 1 << endl;
    return 0;
}