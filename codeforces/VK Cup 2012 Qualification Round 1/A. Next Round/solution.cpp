#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &i: v) {
        cin >> i;
    }
    for(int i=0; i<n; i++) {
        if(i<k) {
            if(v[i] > 0) {
                ans++;
            }
        } else {
            if(v[i] > 0 && v[i] == v[k-1]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}