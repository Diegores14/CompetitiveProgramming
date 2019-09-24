#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, temp;
    cin >> n >> m;
    long long v[n];
    memset( v, 0, sizeof v );
    long long ans = 0; 
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cin >> temp;
            v[i] += temp;
        }
        ans ^= v[i];
    }
    cout << (ans? "Alice" : "Bob" )  << '\n';
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