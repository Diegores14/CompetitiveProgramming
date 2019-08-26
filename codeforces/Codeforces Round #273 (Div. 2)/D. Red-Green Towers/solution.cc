#include <bits/stdc++.h>
using namespace std;
const int len = 894, MMAX = 2e5 + 50, mod = 1e9+7;
int dp[2][MMAX];
long long r, g, h;

/*
int solve( int idx, int sum ) {
    if( idx == h ) { return 1; } 
    int &ans = dp[idx][sum];
    if( ans != -1 ) return ans;
    ans = 0;
    if( sum + idx <= r ) ans = (ans+solve( idx+1, sum+idx ))%mod;
    if( (1LL*idx*(idx+1))/2 - sum <= g ) ans = (ans+solve( idx+1, sum ))%mod;
    return ans;
}
*/

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( int i = 0; i < MMAX; i++ ) {
        dp[1][i] = 1;
    }
    memset(dp[0], 0, sizeof dp[0] );
    cin >> r >> g;
    int b = max( r, g ), a = min( r, g ); 
    h = 1;
    while( a >= h ) { a -= h; h++; }
    if( a ) { b -= h-a; h++; }
    while( b >= h ) { b -= h; h++; }
    int cur = 0;
    for( int i = h-1; i > 0; i--) {
        for( int j = (i*(i-1))/2; j >= 0; j-- ) {
            if( j <= r && (i*(i-1))/2 - j <= g ) {
                if( j + i <= r ){ dp[cur][j] = (dp[cur][j] + dp[cur^1][j+i])%mod; }
                if( (i*(i+1))/2 - j <= g ) { dp[cur][j] = (dp[cur][j] + dp[cur^1][j])%mod; }
            }
        }
        cur ^= 1;
        memset( dp[cur], 0, sizeof dp[cur] );
    }
    cout << dp[cur^1][0] << '\n';
    return 0;
}