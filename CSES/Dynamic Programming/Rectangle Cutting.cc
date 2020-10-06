#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int INF = 1e9;
 
int solve( int a, int b ) {
    if( a==b )  return 0;
    int &ans = dp[a][b];
    if( ans != -1 ) return ans;
    ans = INF;
    for( int i = 1; i <= b/2; i++ ) {
        ans = min( ans, solve(a, i) + solve(a, b-i) + 1 );
    }
    for( int i = 1; i <= a/2; i++ ) {
        ans = min( ans, solve(i, b) + solve(a-i, b) + 1 );
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( int i = 0; i <= 500; i++ ) {
        for( int j = 0; j <= 500; j++ ) {
            dp[i][j] = INF;
        }
    }
    for( int i = 1; i < 501; i++ ) {
        dp[i][i] = 0;
    }
    int a, b;
    cin >> a >> b;
    for( int i = 1; i <= a; i++ ) {
        for( int j = 1; j <= b; j++ ) {
            for( int k = 1; k <= i/2; k++ ) {
                dp[i][j] = min( dp[i][j], dp[k][j]+dp[i-k][j]+1 );
            }
            for( int k = 1; k <= j/2; k++ ) {
                dp[i][j] = min( dp[i][j], dp[i][k]+dp[i][j-k]+1 );
            }
        }
    }
    cout << dp[a][b] << '\n';
    return 0;
}
