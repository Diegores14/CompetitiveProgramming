#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int c, f, tr, vp, vd;
    long double t, x=0, y=0;
    cin >> vp >> vd >> tr >> f >> c;
    x = tr*vp;
    int ans = 0;
    while(true) {
        t = (long double)x/(vd-vp);
        if(t < 0) {
            break;
        }
        x += vp*t;
        if(x<c) {
            ans++;
            x += vp*(t+f);
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}