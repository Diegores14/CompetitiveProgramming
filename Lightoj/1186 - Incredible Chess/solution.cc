#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int b[n], w[n];
    for( int i = 0; i < n; i++ ) {
        cin >> w[i];
    }
    for( int i = 0; i < n; i++ ) {
        cin >> b[i];
    }
    int ans = 0; 
    for( int i = 0; i < n; i++ ) {
        ans ^= (b[i] - w[i] - 1);
    }
    cout << (ans? "white" : "black") << " wins\n";
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