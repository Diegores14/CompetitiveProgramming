#include <bits/stdc++.h>
using namespace std;
int n, w;
int v[35];
map< int, int> dp[35];

int solve( int idx, int sum ) {
    if( sum < 0 ) return 0;
    if( idx == n ) {
        return 1;
    }
    if( dp[idx].count(sum) ) return dp[idx][sum];
    return dp[idx][sum] = solve( idx+1, sum ) + solve( idx+1, sum - v[idx] );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        for( int i = 0; i <= 30; i++) dp[i].clear();
        cin >> n >> w;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i];
        }
        cout << "Case " << cases << ": " << solve(0, w) << '\n';
    }
    return 0;
}