#include <bits/stdc++.h>
using namespace std;
int dp[52][52][52];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s1, s2, s3;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ": ";
        int ans = 0;
        cin >> s1 >> s2 >> s3;
        memset(dp, 0, sizeof dp);
        for(int i = s1.size()-1; i >= 0; i--) {
            for(int j = s2.size()-1; j >= 0; j--) {
                for(int r = s3.size()-1; r >= 0 ; r--) {
                    if(s1[i] == s2[j] && s1[i] == s3[r])
                        dp[i][j][r] = 1 + dp[i+1][j+1][r+1];
                    else {
                        dp[i][j][r] = max(dp[i+1][j][r], max(dp[i][j+1][r], dp[i][j][r+1]) );
                    }
                }
            }
        }
        cout << dp[0][0][0] << '\n';
    }
    return 0;
}