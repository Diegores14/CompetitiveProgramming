#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, l, r;
    cin >> n >> l >> r;
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    long long cant[3] = { r/3 - (l-1)/3, (r+2)/3 - (l+1)/3, (r+1)/3 - l/3};
    /*for(int i: cant) {
        cout << i << '\n';
    }*/
    dp[0][n-1] = cant[0];
    dp[2][n-1] = cant[2];
    dp[1][n-1] = cant[1];
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                dp[j][i] = (dp[j][i] + (cant[k] * dp[(j+3-k)%3][i+1]) % Mod ) % Mod;
            }
        }
    }
    /*1for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cout << dp[j][i] <<  ' ';
        }
        cout << '\n';
    }*/
    cout << dp[0][0] << '\n';
    return 0;
}