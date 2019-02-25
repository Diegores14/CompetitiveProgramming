#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(v[i] < 0 && k) {
            k--;
            v[i] *= -1;
        }
    }
    if(k&1) {
        sort(v.begin(), v.end());
        v[0] *= -1;
    }
    for(int i=0; i<n; i++) {
        ans += v[i];
    }
    cout << ans << '\n';
    return 0;
}