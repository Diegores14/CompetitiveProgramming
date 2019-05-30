#include <bits/stdc++.h>
using namespace std;

string mmin(string &s1, string &s2) {
    if(s1.size() < s2.size()) return s2;
    if(s2.size() < s1.size()) return s1;
    if(s1.size() == s2.size()) {
        for(int i = 0; i <= s1.size(); i++) {
            if(s1[i] < s2[i]) return s1;
            if(s1[i] > s2[i]) return s2;
        }
    }
    return s1;
}


int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    string s1, s2;
    for( int cases = 1; cases <= t; cases++) {
        cin >> s1 >> s2;
        string dp[105][105];
        for(int i = s1.size() - 1; i >= 0 ; i--) {
            for(int j = s2.size() - 1; j >= 0; j--) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = s1[i] + dp[i+1][j+1];
                } else {
                    dp[i][j] = mmin( dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        cout << "Case " << cases << ": ";
        if(dp[0][0].size() == 0) {
            cout << ":(\n";
        } else {
            cout << dp[0][0] << '\n';
        }
    }
    return 0;
}