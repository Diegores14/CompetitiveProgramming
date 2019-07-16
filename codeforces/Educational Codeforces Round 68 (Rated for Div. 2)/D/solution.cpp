#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k; 
    int v1[4] = {0, 1, 1, 1};
    int v2[3] = {0, 1, 1};
    string ans[2] = { "Bob", "Alice"};
    bool dp[20][20];
    for(int k = 0; k < 20; k++) {
        dp[k][0] = 0;
        dp[k][1] = dp[k][2] = 1;
        for(int i = 3; i < 20; i++) {
            dp[k][i] = (dp[k][i-1] == 0 || dp[k][i-2] == 0 || (i-k >= 0 && k != 0 && dp[k][i-k] == 0));
        }
    }
    /*for(int i = 0; i < 20; i++) {
        cout << "Para K = " << i << ' ';
        for(int j = 0; j < 20; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    } */
    cin >> t;
    
    
    while(t--) {
        cin >> n >> k;
        if(n == k) {
            cout << ans[1] << '\n';
            continue;
        }
        if(k%3 == 0) {
            int a = n%(k+1);
            if(a == k) {
                cout << ans[1] << '\n';
            }else {
                cout << ans[v2[a%3]] << '\n';
            }
        } else {
            cout << ans[v2[n%3]] << '\n';
        }
    }
    return 0;
}