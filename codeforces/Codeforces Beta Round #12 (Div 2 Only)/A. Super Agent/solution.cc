#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string v[3];
    for( int i = 0; i < 3; i++ ) {
        cin >> v[i];
    }
    if( v[0][0] == v[2][2] && v[0][2] == v[2][0] && v[0][1] == v[2][1] && v[1][0] == v[1][2] ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}