#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    long long l, r, ans = 0;
    cin >> n >> k;
    vector<long long> extra(n);
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        ans += min(l, r);
        extra[i] = min((l<<1), r) - min(l, r);
    }
    sort(extra.begin(), extra.end(), greater<int>());
    for(int i=0; i<k; i++) {
        ans += extra[i];
    }
    cout << ans << '\n';
    return 0;
}