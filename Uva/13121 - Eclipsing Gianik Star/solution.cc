#include <bits/stdc++.h>
using namespace std;
const int tam = 365;
int a[tam], b[tam];
int cnt[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p;
    while(cin >> n) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; i++) {
            cin >> p >> a[i] >> b[i];
            a[i] = (a[i]%360 + 360) % 360;
            cnt[a[i]]++;
        }
        int ans = -1;
        for(int time = 0; time <= 360 && ans == -1; time++) {
            for(int i = 0; i < n; i++) {
                if(cnt[a[i]] >  1) {
                    ans = time;
                }
                cnt[a[i]] = 0;
            }
            for(int i = 0; i < n; i++) {
                a[i] += b[i];
                a[i] = (a[i]%360 + 360) % 360;
                cnt[a[i]]++;
            }
        }
        if( ans != -1 ) {
            cout << ans << '\n';
        } else {
            cout << "GIANIK IS NEVER ECLIPSED\n";
        }
    }
    return 0;
}