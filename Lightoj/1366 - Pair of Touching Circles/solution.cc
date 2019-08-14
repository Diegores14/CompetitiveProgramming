#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, h, w;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> h >> w;
        long long ans = 0;
        for( int i = 0; i <= h/2; i++ ) {
            for( int j = 0; j <= w/2; j++) {
                int len = sqrt( i*i + j*j );
                if( len*len != i*i + j*j) continue;
                for( int r = 1; r < len; r++ ) {
                    int y1 = min( -r, i-len+r ), y2 = max( r, i+len-r );
                    int x1 = min( -r, j-len+r ), x2 = max( r, j+len-r );
                    int x = x2 - x1;
                    int y = y2 - y1;
                    if( x > w || y > h )continue;
                    int sum = ( h-y+1 )*( w-x+1 );
                    if( j && i ) sum *=2;
                    ans += sum;
                }
            }
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}