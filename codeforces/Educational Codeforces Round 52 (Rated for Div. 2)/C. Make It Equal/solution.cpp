#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    long long H = 0,  mmin = 1e9;
    cin >> n >> k;
    vector<long long> h(n);
    for(long long &i: h) {
        cin >> i;
        H = max( H, (long long)i );
        mmin = min( mmin, (long long)i );
    }
    sort(h.begin(), h.end());
    vector<long long> prefix(H+1), v(H);
    int l = 0;
    for(int i=0; i<n; i++) {
        while(l < h[i]) {
            v[l++] = n-i;
        }
    }
    for(int i=0; i<H; i++) {
        prefix[i+1] = v[i] + prefix[i];
    }
    int ans = 0;
    while(mmin < H) {
        int i=mmin+1;
        while(i <= H && prefix[i] - prefix[mmin] <= k) {
            i++;
        }
        ans++;
        mmin = i-1;
    }
    cout << ans << '\n';
    return 0;
}