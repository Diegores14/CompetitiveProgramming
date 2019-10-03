#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s[2];
    cin >> t;
    while( t-- ) {
        int n;
        cin >> n >> s[0] >> s[1];
        bool ans = true;
        int pos = 0;
        for( int i = 0; i < n; i++ ) {
            if( '2' < s[pos][i] ) {
                if( '2' < s[pos^1][i] ) {
                    pos ^= 1;
                } else {
                    ans = false;
                    break;
                }
            }
        }
        cout << ((pos&1 && ans)? "YES" : "NO") << '\n';
    }
    return 0;
}