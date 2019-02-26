#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, x, y, val;
    cin >> n >> m;
    vector<int> v(n+1, 0);
    for(int i=0; i<m; i++) {
        cin >> x >> y >> val;
        v[x] -= val;
        v[y] += val;
    }
    long long ans = 0;
    for(int i=0; i<=n; i++) {
        if(v[i] < 0) {
            ans -= v[i];
        }
    }
    cout << ans << '\n';
    return 0;
}