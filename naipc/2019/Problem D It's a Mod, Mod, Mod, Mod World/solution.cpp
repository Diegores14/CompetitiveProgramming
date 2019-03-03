#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int w;
    cin >> w;
    unsigned long long p, q, n;
    while(w--) {
        cin >> p >> q >> n;
        unsigned long long ans = 0;
        for(int i=1; i<=n; i++) {
            ans += (p*i)%q;
        }
        cout << ans << '\n';
    }
    return 0;
}