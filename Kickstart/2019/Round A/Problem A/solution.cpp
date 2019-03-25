#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, p, temp;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case #" << k << ": ";
        cin >> n >> p;
        vector<int> prefix(n+1, 0), v(n);
        for(int &i: v) {
            cin >> i;
        }
        sort(v.begin(), v.end());
        for(int i=1; i<=n; i++) {
            prefix[i] += v[i-1] + prefix[i-1];
        }
        long long ans = (long long) 1e18;
        for(int i=p; i<=n; i++) {
            ans = min(ans, (long long)(prefix[i] - prefix[i-1])*p - (prefix[i] - prefix[i-p]));
        }
        cout << ans << '\n';
    }
    return 0;
}