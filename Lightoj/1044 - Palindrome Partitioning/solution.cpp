#include <bits/stdc++.h>
using namespace std;
const int tam = 1005;
int dp[tam];
bool dpPalindrome[tam][tam];

int main() {
    int t, n;
    string s;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> s;
        n = s.size();
        memset(dpPalindrome, 0, sizeof dpPalindrome);
        for(int i=0; i<n; i++) {
            for(int j=0; j < 2 && i+j < n; j++) {
                if(s[i] == s[i+j]) {
                    dpPalindrome[i][i+j] = true;
                }
            }
        }
        for(int i=2; i<n; i++) {
            for(int j=0; j < n && i + j < n; j++) {
                if(s[j] == s[i+j] && dpPalindrome[j+1][i+j-1]) {
                    dpPalindrome[j][i+j] = true;
                }
            }
        }
        for(int i=0; i<n; i++) dp[i] = 100000;
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j=0; i+j < n; j++) {
                if(dpPalindrome[i][i+j]) {
                    dp[i] = min(dp[i], dp[i+j+1] + 1);
                }
            }
        }
        cout << dp[0] << '\n';
    }
    return 0;
}