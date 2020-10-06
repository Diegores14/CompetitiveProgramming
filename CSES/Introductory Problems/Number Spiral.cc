#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long t;
    cin  >>  t;
    long long x, y;
    while( t-- ) {
        cin >> y >> x;
        long long line = max(x, y);
        long long ans;
        if( x < y ) {
            if( line&1 ) {
                ans = (line-1)*(line-1) + x;
            } else {
                ans = line*line - x + 1;
            }
        } else {
            if( line&1 ) {
                ans = line*line - y + 1;
            } else {
                ans = (line-1)*(line-1) + y;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
