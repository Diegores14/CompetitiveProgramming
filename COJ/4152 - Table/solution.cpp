#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, k;
    cin >> a >> b >> k;
    if(a > b) {
        swap(a, b);
    }
    int ans = 0;
    if(a >= k) {
        a -= k;
        ans += b/k;
    }
    if(a >= k) {
        a -= k;
        ans += b/k;
    }
    if(a >= k && b >= k) {
        b -= k;
        ans += a/k;
    }
    if(a >= k && b >= k) {
        b -= k;
        ans += a/k;
    }
    cout << ans << '\n';
    return 0;
}