#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, d;
    cin >> n;
    int v[40005];
    memset( v, 0, sizeof v );
    for( int i = 0; i < n; i++ ) {
        cin >> x >> d;
        x += 20000;
        if( v[x+d] == -d ) {
            cout << "YES\n";
            return 0;
        }
        v[x] = d;
    }
    cout << "NO\n";
    return 0;
}