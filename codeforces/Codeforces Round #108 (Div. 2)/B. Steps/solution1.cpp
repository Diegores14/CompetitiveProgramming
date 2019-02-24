#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, x, y, k, dx, dy;
    long long ans = 0;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < k; i++) {
        cin >> dx >> dy;
        int l=0, r=1e9;
        while(r-l != 1) {
            int mid = (l+r)>>1;
            if(0 < x+mid*dx && x+mid*dx <=n && 0 < y+mid*dy && y+mid*dy <=m) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ans += l;
        x += l*dx;
        y += l*dy;
    }
    cout << ans << '\n';
    return 0;
}