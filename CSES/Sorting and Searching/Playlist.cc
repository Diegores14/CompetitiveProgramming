#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    int pos = -1;
    map< int, int > m;
    for( int i = 0, temp; i < n; i++ ) {
        cin >> temp;
        if( m.count(temp) ) {
            pos = max( pos, m[temp] );
        }
        m[temp] = i;
        ans = max( ans, i-pos );
    }
    cout << ans << '\n';
    return 0;
}