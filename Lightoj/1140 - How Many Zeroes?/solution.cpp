#include <bits/stdc++.h>
using namespace std;
long long dp[33][2][33][2];

long long dptop(int idx, bool istop, string top, int cant, bool sum) {
    if(top.size() == idx) return (sum)? cant : 1;
    long long &ans = dp[idx][istop][cant][sum];
    if(ans != -1) return ans;
    char limit = istop? top[idx] : '9';
    ans = 0;
    for(char i = '0'; i <= limit; i++) {
        ans += dptop(idx+1, istop && i == limit, top, cant + (i == '0' && sum), sum || i != '0');
    }
    return ans; 
}

int main() {
    //ios_base__sync_with_stdio(false); cin.tie(NULL);
    long long t, a, b;
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cout << "Case " << r << ": ";
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        b = dptop(0, true, to_string(b), 0, false);
        memset(dp, -1, sizeof dp);
        a = dptop(0, true, to_string(a-1), 0, false);
        cout << b - a << '\n';
    }
    return 0;
}