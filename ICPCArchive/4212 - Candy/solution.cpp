#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    while(cin >> n >> m, n || m) {
        vector< vector<int> > v(n, vector<int>(m) ), dp(n, vector<int>(m) );
        
        for(int i = 0; i < n; i++) {
            for(int &j: v[i]) {
                cin >> j;
            }
        }

        for(int i=0; i<n; i++) {
            if(0<m)dp[i][0] = v[i][0];
            if(1<m)dp[i][1] = v[i][1];
            if(2<m)dp[i][2] = v[i][2] + dp[i][0];
            for(int j=3; j<m; j++) {
                dp[i][j] = v[i][j] + max(dp[i][j-2], dp[i][j-3]);
            }
        }
        vector<int> dps(n);
        for(int i=0; i<3 && i<n; i++) {
            dps[i] = dp[i][m-1];
        }
        if(0<n && 1 < m)dps[0] = max(dps[0], dp[0][m-2]);
        if(1<n && 1 < m)dps[1] = max(dps[1], dp[1][m-2]);
        if(2<n && 1 < m)dps[2] = max(dps[2], dp[2][m-2]);
        if(2<n) dps[2] += dps[0];
        for(int j=3; j<n; j++) {
            if(1<m)
                dps[j] = max(dp[j][m-2], dp[j][m-1]) + max(dps[j-2], dps[j-3]);
            else
            {
                dps[j] = dp[j][m-1] + max(dps[j-2], dps[j-3]);
            }
            
        }
        if(1 < n) {
            cout << max(dps[n-2], dps[n-1]) << '\n';
        } else {
            cout << dps[0] << '\n';
        }
        
    } 
    return 0;
}