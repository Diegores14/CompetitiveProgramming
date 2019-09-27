#include <bits/stdc++.h>
using namespace std;

int g( int x ) {
    if( x == 0 | x == 1 ) return 0;
    if( x%2 == 0 ) return x/2;
    else  return g(x/2);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, temp;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n;
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
            cin >> temp;
            ans ^= g(temp);
        }
        cout << "Case " << cases << ": " << (ans? "Alice" : "Bob" ) << '\n';
    }
    return 0;
}