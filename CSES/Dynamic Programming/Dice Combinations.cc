#include <bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
const int tam = 1e6+10;
int dp[tam];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    dp[0] = 1;
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= 6; j++ ) {
            if( 0 <= i-j ) {
                dp[i] = (dp[i]+dp[i-j])%mod;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
