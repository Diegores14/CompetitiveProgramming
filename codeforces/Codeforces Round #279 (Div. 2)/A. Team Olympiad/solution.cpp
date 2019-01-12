#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector<int> v[3];
    for(int i=1; i<=n; i++) {
        cin >> temp;
        v[temp-1].emplace_back(i);
    }
    int ans = min(v[0].size(), min(v[2].size(), v[1].size()));
    cout << ans << '\n';
    for(int i=0; i<ans; i++) {
        cout << v[0][i] << ' ' << v[1][i] << ' ' << v[2][i] << '\n';
    }
    return 0;
}