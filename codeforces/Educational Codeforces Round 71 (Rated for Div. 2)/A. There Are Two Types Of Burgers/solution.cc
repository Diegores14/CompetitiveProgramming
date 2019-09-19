#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, b, p, f, h, c;
    cin >> t;
    while( t-- ) {
        cin >> b >> p >> f >> h >> c;
        int ans = 0;
        b /= 2;
        if( c < h ) {
            int temp = min( p, b );
            ans += temp*h;
            p -= temp;
            b -= temp;
            temp = min( f, b );
            ans += temp*c;
            b -= temp;
            f -= temp;
        } else {
            int temp = min( f, b );
            ans += temp*c;
            f -= temp;
            b -= temp;
            temp = min( p, b );
            ans += temp*h;
            b -= temp;
            p -= temp;
        }
        cout << ans << '\n';
    }
    return 0;
}