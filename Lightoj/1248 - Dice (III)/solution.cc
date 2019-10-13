#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    double ans = 0;
    for( int i = n-1; i >= 0; i-- ) {
        ans += double(n)/(n-i);
    }
    cout << ans << '\n';
}


int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}