#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, h, temp;
    cin >> n >> m >> h;
    int ans[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[i][j] = 1000000;
        }
    }
    for(int i=0; i<m; i++) {
        cin >> temp;
        for(int j=0; j<n; j++) {
            ans[j][i] = min(ans[j][i], temp);
        }
    }
    for(int i=0; i<n; i++) {
        cin >> temp;
        for(int j=0; j<m; j++) {
            ans[i][j] = min(ans[i][j], temp);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            if(temp == 0)
                ans[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j] << ((j==m-1)? '\n' : ' ');
        }
    }
    return 0;
}