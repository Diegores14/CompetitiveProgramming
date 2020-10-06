#include <bits/stdc++.h>
using namespace std;
const int tam = 1001;
int dp[tam][tam];
const int mod = 1e9+7;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    char v[n][n];
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin >> v[i][j];
        }
    }
    dp[0][0] = v[0][0] != '*';
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( v[i][j] == '*' ) continue;
            if( 0 < i )
                dp[i][j] += dp[i-1][j];
            if( 0 < j )
                dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1] << '\n';
    return 0;
}
