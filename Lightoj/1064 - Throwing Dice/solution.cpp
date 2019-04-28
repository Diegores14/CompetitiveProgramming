#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[27][165];

unsigned long long exponentation(int exp) {
    unsigned long long ans = 1;
    unsigned long long b = 6;
    while(exp) {
        if(exp&1) {
            ans *= b;
        }
        b *= b;
        exp >>= 1;
    }
    return ans;
}

unsigned long long GCD(unsigned long long a, unsigned long long b) {
    return a? GCD(b%a, a) : b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, x;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> n >> x;
        memset(dp, 0, sizeof dp);
        for(int i=x; i<165; i++) {
            dp[n][i] = 1;
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = 158; j >= 0; j--) {
                for(int r=1; r <= 6; r++) {
                    dp[i][j] += dp[i+1][j+r];
                }
            }
        }
        unsigned long long denominator = exponentation(n), d = GCD(dp[0][0], denominator);
        if(denominator == d) {
            cout << (dp[0][0]? 1 : 0) << '\n';
        } else {
            cout << dp[0][0]/d << '/' << denominator/d << '\n';
        }
    }
    return 0;
}