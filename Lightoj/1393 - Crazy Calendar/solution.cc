#include <bits/stdc++.h>
using namespace std;

void solve() {
    int r, c, ans = 0, temp;
    cin >> r >> c;
    for( int i = 0; i < r; i++ ) {
        for( int j = 0; j < c; j++ ) {
            cin >> temp;
            if( (r+c)%2 != (i+j)%2 )
                ans ^= temp;
        }
    }
    cout << ( ans? "win" : "lose" ) << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}