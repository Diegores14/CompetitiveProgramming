#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+2;
long long dp[tam][101];
int mod = 1e9+7;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int x[n];
    for( int i = 0; i < n; i++ ) {
        cin >> x[i];
    }
    for( int i = 1; i <= m; i++ ) {
        dp[0][i] = x[0] == 0 || x[0] == i ? 1 : 0;
    }
    for( int i = 1; i < n; i++ ) {
        if( x[i] == 0 ) {
            for( int j = 1; j <= m; j++ ) {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
            }
        } else {
            dp[i][x[i]] = (dp[i-1][x[i]-1]+dp[i-1][x[i]]+dp[i-1][x[i]+1])%mod;
        }
    }
    long long sum = 0;
    for( int i = 1; i <= m; i++ ) {
        sum = (sum+dp[n-1][i])%mod;
    }
    cout << sum << '\n';
    return 0;
}
