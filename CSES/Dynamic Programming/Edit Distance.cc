#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n1, n2;
int dp[5001][5001];
int INF = 1e9;
 
int solve( int i, int j ) {
    if( i == s1.size() && j == s2.size() ) return 0;
    if( i == s1.size() ) return s2.size()-j;
    if( j == s2.size() ) return s1.size()-i;
    int &ans = dp[i][j];
    if( s1[i] == s2[j] ) {
        ans = solve(i+1, j+1);
    } else {
        ans = solve( i+1, j+1)+1;
    }
    ans = min(ans, solve(i, j+1)+1);
    ans = min(ans, solve(i+1, j)+1);
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s1 >> s2;
    if( s1.size() > s2.size()  ) swap(s1, s2);
    n1 = s1.size();
    n2 = s2.size();
    for( int i = 0; i < n1; i++ ) {
        dp[i][n2] = n1-i;
    }
    for( int i = 0; i < n2; i++ ) {
        dp[n1][i] = n2-i;
    }
    for( int i = n1-1; i >= 0; i-- ) {
        for( int j = n2-1; j >= 0; j-- ) {
            if( s1[i] == s2[j] ) {
                dp[i][j] = dp[i+1][j+1];
            } else {
                dp[i][j] = dp[i][j+1]+1;
            }
            dp[i][j] = min(dp[i][j], dp[i+1][j+1]+1);
            dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
        }
    }
    // for( int i = 0; i <= n1; i++) {
    //     for( int j = 0; j <= n2; j++ ) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[0][0] << '\n';
    return 0;
}
