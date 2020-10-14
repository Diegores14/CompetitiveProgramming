#include <bits/stdc++.h>
using namespace std;
long long dp[2000][2000];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q;
    char temp;
    cin >> n >> q;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin >> temp;
            dp[i+1][j+1] = (temp=='*') + dp[i][j+1] + dp[i+1][j] - dp[i][j];
        }
    }
    while( q-- ) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }
    return 0;
}