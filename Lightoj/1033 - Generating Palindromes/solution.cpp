#include <bits/stdc++.h>
using namespace std;
int dp[105][105];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case " << k << ": ";
        cin >> s;
        n = s.size();
        string temp = s;
        reverse(s.begin(), s.end());
        memset(dp, 0, sizeof dp);
        for(int i = n-1; i >= 0; i--) {
            for(int j=n-1; j >= 0; j--) {
                if(s[i] == temp[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        cout << n - dp[0][0] << '\n';
    }
    return 0;
}