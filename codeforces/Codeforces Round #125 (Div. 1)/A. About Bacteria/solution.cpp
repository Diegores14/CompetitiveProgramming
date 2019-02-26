#include <bits/stdc++.h>
using namespace std;
long double e = 1e-15;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long k, b, n, t, temp;
    cin >> k >> b >> n >> t;
    long long ans = n;
    //cout << (t-k*t-b)/(1-k-b) << ' ' << exponetation(k, 11) << '\n';
    if(k!=1) {
        ans = ceil(n + log((long double)(1-k-b)/(t-t*k-b)) / log(k)-e);
    }
    else {
        ans = (b*n-t+b)/b;
    }
    if(ans < 0) {
        ans = 0;
    }
    cout << ans << '\n';
    return 0;
}