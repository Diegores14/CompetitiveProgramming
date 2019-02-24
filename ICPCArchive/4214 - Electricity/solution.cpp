#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d, m, y, c;
    vector<int> v({0,31,59,90,120,151,181,212,243,173,304,334,365}),
                v1({0,31,60,91,121,152,182,213,244,174,305,335,366});
    while(cin >> n, n) {
        int da = 0, ma = 0, ya = 0, ca = 0, ans = 0, cant = 0;
        while(n--) {
            cin >> d >> m >> y >> c;
            if(y == ya) {
                if(y%400 == 0 || (y%4 == 0 && y%100)) {
                    if(v1[m-1] + d - v1[ma-1] - da == 1) {
                        ans += c-ca;
                        cant++;
                    }
                } else {
                    if(v[m-1] + d - v[ma-1] - da == 1) {
                        ans += c-ca;
                        cant++;
                    }
                }
            } else {
                if(y-ya == 1 && da == 31 && d == 1 && ma == 12 && m == 1) {
                    ans += c-ca;
                    cant++;
                }
            }
            da = d; ma = m; ya = y; ca = c;
        }
        cout << cant << ' ' << ans << '\n';
    }
    return 0;
}