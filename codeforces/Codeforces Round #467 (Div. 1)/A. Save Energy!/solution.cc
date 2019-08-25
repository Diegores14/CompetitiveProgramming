#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k, d, t;
    cin >> k >> d >> t;
    t <<= 1;
    long long period = ((k+d-1)/d) * d;
    long long cooking = k + period;
    long double ans = (t/cooking) * period;
    long long rem = t%cooking;
    if( rem > 2*k ) {
        ans += rem - k;
    } else {
        ans += (long double)rem/2;
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}