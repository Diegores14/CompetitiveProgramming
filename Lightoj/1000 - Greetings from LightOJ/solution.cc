#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, a, b;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b;
        cout << "Case " << cases << ": " << a+b << '\n';
    }
    return 0;
}