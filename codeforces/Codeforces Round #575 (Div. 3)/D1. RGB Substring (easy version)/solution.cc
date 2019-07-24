#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    string pre[3] = { "RGB", "GBR", "BRG"};
    while(q--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int prefixSum[3][n+1];
        memset(prefixSum, 0, sizeof prefixSum);
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j <= n; j++) {
                prefixSum[i][j] = (s[j-1] != pre[i][j%3]) + prefixSum[i][j-1];
                //cout << "Debug " << prefixSum[i][j] << '\n';
            }
        }
        int ans = n;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j + k <= n; j++) {
                ans = min(ans, prefixSum[i][j+k] - prefixSum[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}