#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int v[2];
    int ans = 0;
    for( int i = 0; i < 2*n; i++ ) {
        cin >> v[i&1];
        if( i&1 )
            ans ^= (v[1] - v[0] - 1);
    }
    cout << (ans? "Alice" : "Bob" ) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}