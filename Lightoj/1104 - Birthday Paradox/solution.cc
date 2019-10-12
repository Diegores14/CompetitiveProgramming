#include <bits/stdc++.h>
using namespace std;



void solve() {
    double n; 
    cin >> n;
    double p = 1;
    int ans = 1;
    while( p > 0.5 ) {
        p = (1 - (ans/n))*p;
        ans++;
    }
    cout << ans-1 << '\n';
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