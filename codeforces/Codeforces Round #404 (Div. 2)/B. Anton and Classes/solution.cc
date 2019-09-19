#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, x, y;
    cin >> n;
    long long x1 = 0, y1 = 1e18, x2 = 0, y2 = 1e18;
    for( int i = 0; i < n; i++ ) {
        cin >> x >> y;
        x1 = max(x1, x);
        y1 = min(y1, y);
    }
    int m;
    cin >> m;
    for( int i = 0; i < m; i++ ) {
        cin >> x >> y;
        x2 = max(x2, x);
        y2 = min(y2, y);
    }
    long long ans = 0;
    if( y1 <= x2 ) {
        ans = max( ans, x2-y1 );
    }
    if( y2 <= x1 ) {
        ans = max( ans, x1-y2 );
    }
    cout << ans << '\n';
    return 0;
}