#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int ans1 = 0, ans2 = 0;
    vector<string> v(8);
    for( int i = 0 ; i < 8; i++ ) {
        cin >> v[i];
    }
    for( int i = 0; i < 8; i++ ) {
        bool ok = true;
        for( int j = 0; j < 8; j++ ) {
            if( v[i][j] != 'B' ) {
                ok = false;
                break;
            }
        }
        ans1 += ok;
    }
    for( int i = 0; i < 8; i++ ) {
        bool ok = true;
        for( int j = 0; j < 8; j++ ) {
            if( v[j][i] != 'B' ) {
                ok = false;
                break;
            }
        }
        ans2 += ok;
    }
    if( ans1 == 8 && ans2 == 8 ) cout << 8 << '\n';
    else cout << ans1 + ans2 << '\n';
    return 0;
}