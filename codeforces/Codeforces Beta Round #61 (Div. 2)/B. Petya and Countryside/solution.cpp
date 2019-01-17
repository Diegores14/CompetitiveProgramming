#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n), greater(n, 1), lesser(n, 1);
    for(int &i: v) {
        cin >> i;
    }
    for(int i=1; i<n; i++) {
        if(v[i-1] <= v[i]) {
            lesser[i] += lesser[i-1];
        }
        if(v[n-i] <= v[n-i-1]) {
            greater[n-i-1] += greater[n-i];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, lesser[i] + greater[i] -1);
    }
    cout << ans << '\n';
    return 0;
}