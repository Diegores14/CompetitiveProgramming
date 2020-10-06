#include <bits/stdc++.h>
using namespace std;
long long dp[5001][5001];
long long v[5001]; 
long long sum[5001];
 
long long solve( int l, int r ) {
    if( l == r ) return v[l];
    long long &ans = dp[l][r];
    if( ans != -1 ) return ans;
    ans = sum[r+1]-sum[l]-solve(l+1, r);
    ans = max( ans, sum[r+1]-sum[l]-solve(l, r-1) );
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n; 
    memset(dp, -1, sizeof dp );
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
        sum[i+1] = v[i]+sum[i];
    }
    cout << solve(0, n-1) << '\n';
    return 0;
}
