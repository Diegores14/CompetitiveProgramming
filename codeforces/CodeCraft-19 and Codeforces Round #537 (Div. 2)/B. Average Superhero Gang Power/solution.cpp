#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long  n, k, m;
    cin >> n >> k >> m;
    vector<long long> v(n), prefix(n+1);
    for(long long &i: v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        prefix[i+1] = prefix[i] + v[i];
    }
    long double ans = -1;
    for(int i=0; i<n && i<=m; i++) {
        long long x = min(m-i, k*(n-i));
        ans = max(ans, (long double)(prefix[n] - prefix[i] + x) / (n-i));
    }
    cout << fixed << setprecision(18) << ans << '\n';
    return 0;
}