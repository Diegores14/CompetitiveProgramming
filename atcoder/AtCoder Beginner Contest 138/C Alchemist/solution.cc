#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int v[n];
    for( int &i: v ) {
        cin >> i;
    }
    sort(v, v+n);
    long double ans = v[0];
    for( int i = 1; i < n; i++ ) {
        ans += v[i];
        ans /= 2;
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}