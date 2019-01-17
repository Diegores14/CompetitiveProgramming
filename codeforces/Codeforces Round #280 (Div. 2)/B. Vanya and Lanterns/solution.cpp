#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int ans = max(v[0], l-v[n-1]) * 2;
    for(int i=1; i<n; i++) {
        ans = max(ans, v[i]-v[i-1]);
    }
    cout << (ans>>1) << ((ans&1)? ".5" : ".0") << '\n';
    return 0;
}