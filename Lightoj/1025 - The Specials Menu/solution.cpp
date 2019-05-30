#include <bits/stdc++.h>
using namespace std;
long long dp[61][61];
string s;

long long solve(int i, int j) {
    if( i == j )  return 1;
    if( i > j ) return 0;
    long long &ans = dp[i][j];
    if(ans != -1) return ans;
    // we remove solve(i+1, j-1) because is generate for solve(i+1, j) and solve(i, j-1)
    ans = solve(i+1, j) + solve(i, j-1) - solve(i+1, j-1);
    if(s[i] == s[j]) ans += solve(i+1, j-1) + 1;
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << "Case " << cases << ": " << solve(0, s.size()-1) << '\n';
    }
    return 0; 
}