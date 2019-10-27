#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    int v[205];
    memset( v, 0, sizeof v );
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        v[temp+100] = 1;
    }
    bool ok = false;
    for( int i = 0; i < 205; i++ ) {
        if( v[i] ) {
            if( ok ) {
                cout << i-100 << '\n';
                return 0;
            } else {
                ok = true;
            }
        }
    }
    cout << "NO\n";
    return 0;
}