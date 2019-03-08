#include <bits/stdc++.h>
using namespace std;
vector<int> v(100005);
vector<int> dp(100005);

int bs(int val, int r) {
    int l = 0;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        if(val > v[mid]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        int temp1 = v[i]-89;
        int temp2 = v[i]-1439;
        dp[i] = dp[i-1] + 20;
        dp[i] = min(dp[i], dp[bs(temp1, i)] + 50);
        dp[i] = min(dp[i], dp[bs(temp2, i)] + 120);
        cout << dp[i] - dp[i-1] << '\n';
    }
    return 0;
}