#include <bits/stdc++.h>
using namespace std;
int dp[501][62626];
int mod = 1e9+7;
 
long long exp( long long b, long long e ) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans*b)%mod;
        }
        e >>= 1;
        b = (b*b)%mod;
    }
    return ans;
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( int i = 0; i <= 500; i++ ) {
        dp[i][0] = 1;
    }
    long long n;
    cin >> n;
    for( int j = 1; j < 62626; j++ ){
        for( int i = 1; i <= n; i++ ) {
            dp[i][j] = dp[i-1][j];
            if( 0 <= j-i ) {
                dp[i][j] = (dp[i][j]+dp[i-1][j-i])%mod;
            }
        }
    }
    // for( int j = 0; j <= ) {
    //     for( int i = 0; i <= n; i++ ) {
 
    //     }
    // }
    if( n*(n+1)%4 == 0)
        cout << (dp[n][n*(n+1)/4]*exp(2,mod-2))%mod << '\n';
    else 
        cout << 0 << '\n';
    return 0;
}
