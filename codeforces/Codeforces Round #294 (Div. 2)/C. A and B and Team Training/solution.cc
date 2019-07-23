#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        if( (n-i) >= 0 && (m-2*i) >= 0) {
            ans = max(ans, i + min((n-i)/2, (m-2*i)));
        }
    }
    cout << ans << '\n';
    return 0;
}