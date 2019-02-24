#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, x, y, k, dx, dy;
    long long ans = 0;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < k; i++) {
        cin >> dx >> dy;
        long long temp = 1e10;
        if(dx>0) {
            temp = (n-x)/dx;
        }
        if(dx<0) {
            temp = (1-x)/dx;
        }
        if(dy>0) {
            temp = min(temp, (m-y)/dy);
        }
        if(dy<0) {
            temp = min(temp, (1-y)/dy);
        }
        ans += temp;
        x += temp*dx;
        y += temp*dy;
    }
    cout << ans << '\n';
    return 0;
}