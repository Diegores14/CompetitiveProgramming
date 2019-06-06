#include <bits/stdc++.h>
using namespace std;
const int tam = 105;
int n;
int a[tam];
int dp[tam][tam][2];

int solve(int l, int r, int turn) {
    if(r < l ) return 0;
    int &ans = dp[l][r][turn];
    if( ans != -1000000000 ) return ans;
    int temp;
    if(turn == 0) {
        temp = 0;
        for(int i = l; i <= r; i++) {
            temp += a[i];
            ans = max(ans, temp + solve(i+1, r, 1));
        }
        temp = 0;
        for(int i = r; i >= l; i--) {
            temp += a[i];
            ans = max(ans, temp + solve(l, i-1, 1));
        }
    } else {
        temp = 0;
        ans *= -1;
        for(int i = l; i <= r; i++) {
            ans = min(ans, solve(i+1, r, 0));
        }
        temp = 0;
        for(int i = r; i >= l; i--) {
            ans = min(ans, solve(l, i-1, 0));
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n;
        int total = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        for(int i = 0; i < tam; i++) {
            for(int j = 0; j < tam; j++) {
                dp[i][j][0] = dp[i][j][1] = -1000000000;
            }
        }
        int ans = solve(0, n-1, 0);
        int other = total - ans;
        cout << "Case " << cases << ": " << ans - other << '\n';
    }
    return 0;
}