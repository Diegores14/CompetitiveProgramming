#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int b, k;
string s;
long long dp[1<<16][20];

long long solve(int mask,int acc, int p = 1) {
    if((1<<s.size())-1 == mask) return acc == 0;
    long long &ans = dp[mask][acc];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if((mask&(1<<i)) == 0) {
            ans += solve(mask|(1<<i), (acc + p * m[s[i]]) % k, (p*b) % k);
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    for(char i : {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'} ) {
        m[i] = m.size();
    }
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> b >> k >> s;
        memset(dp, -1, sizeof dp);
        cout << "Case " << cases << ": " << solve(0, 0) << '\n';
    }
    return 0;
}