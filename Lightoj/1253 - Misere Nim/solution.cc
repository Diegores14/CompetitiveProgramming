#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, temp;
    int ones = 0;
    cin >> n;
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        ones += (temp == 1);
        ans ^= temp;
    }
    if( ones == n ) cout << ( (n&1)? "Bob" : "Alice" ) << '\n';
    else cout << ((ans==0)? "Bob" : "Alice") << '\n';
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