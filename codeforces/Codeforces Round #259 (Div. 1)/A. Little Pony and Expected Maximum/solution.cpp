#include <bits/stdc++.h>
using namespace std;

long double exponentation( long double b, int e) {
    long double ans = 1;
    while(e) {
        if(e&1) {
            ans *= b;
        }
        b *= b;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    long double ans = 0;
    for(int i=1; i<=m; i++) {
        ans += i*(exponentation((long double)i/m, n) - exponentation((long double)(i-1)/m, n));
    }
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}