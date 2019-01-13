#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i=1; i<n; i++) {
        if(v[0] < v[i] && v[i] < v[n-1]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}