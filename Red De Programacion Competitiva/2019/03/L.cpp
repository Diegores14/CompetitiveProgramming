#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    int mmax = 0;
    cin >> n;
    int v[n+1];
    int ans = 0;
    memset(v, 0, sizeof v);
    bool flag = false;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        for(; a<=b; a++) {
            v[a]++;
        }
    }
    for(int i=0; i<=n; i++) {
        if(v[i] == i) {
            flag = true;
            ans = i;
        }
    }
    if(flag) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}