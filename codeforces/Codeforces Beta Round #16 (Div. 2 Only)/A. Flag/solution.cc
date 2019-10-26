#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    for( int i = 1; i < n; i++ ) {
        if( v[i-1][0] == v[i][0] ) {
            cout << "NO\n";
            return 0;
        }
    }
    for( int i = 0; i < n; i++ ) {
        for( int j = 1; j < m; j++ ) {
            if( v[i][j-1] != v[i][j] ) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}