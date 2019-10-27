#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    bool v[3002];
    memset( v, 0, sizeof v );
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        v[temp] = true;
    }
    for( int i = 1; i < 3002; i++ ) {
        if( !v[i] ) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}