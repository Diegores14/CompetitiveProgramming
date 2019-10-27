#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    map< string, int > m;
    int ans = 0, n = s.size();
    for( int i = 0; i < n; i++ ) {
        for( int j = 1; i+j <= n; j++ ) {
            m[ s.substr(i, j) ]++;
            if( m[ s.substr(i, j) ] >= 2 ) {
                ans = max( ans, j );
            }
        }
    }
    cout << ans << '\n';
    return 0;
}