#include <bits/stdc++.h>
using namespace std;
int v[1000], a[1000];
int dp[1000][100001];
 
int solve(int idx, int x ) {
    if( idx == 0 ) return x >= v[0]? a[0]: 0;
    int ans;
    ans = solve(idx-1, x);
    if( 0 <= x-v[idx] ) {
        ans = max( ans, solve(idx-1, x-v[idx])+a[idx]);
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for( int i = 0; i <= x; i++ ) {
        dp[0][i] = i >= v[0]? a[0]: 0;
    }
    for( int i = 1; i < n; i++ ) {
        for( int j = 0; j <= x; j++ ) {
            dp[i][j] = dp[i-1][j];
            if( v[i] <= j ) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+a[i]);
            }
        }
    }
    cout << dp[n-1][x] << '\n';
    return 0;
}
