#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, x2, y1, y2, n, x, y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> x >> y;
        cout << ( ( x1 <= x && x <= x2 && y1 <= y && y <= y2)? "Yes" : "No") << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ":\n";
        solve();
    }
    return 0;
}