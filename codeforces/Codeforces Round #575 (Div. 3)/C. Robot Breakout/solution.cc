#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, x, y, a, b, c, h;
    cin >> q;
    while(q--) {
        int l = -1e5, r = 1e5, u = 1e5, d = -1e5;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> a >> b >> c >> h;
            if(a == 0) {
                l = max(l, x);
            }
            if(b == 0) {
                u = min(u, y);
            }
            if(c == 0) {
                r = min(r, x);
            }
            if(h == 0) {
                d = max(d, y);
            }
        }
        //cout << "debug " << l << ' ' << r << ' ' << d << ' ' << u << '\n';
        if(l <= r && d <= u) {
            cout << 1 << ' ' << l << ' ' << d << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}