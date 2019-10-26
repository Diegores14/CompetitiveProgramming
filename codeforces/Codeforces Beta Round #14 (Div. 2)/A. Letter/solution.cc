#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    int r = 0, l = 100, top = 100, bottom = 0;
    cin >> n >> m;
    string v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
        for( int j = 0; j < m; j++ ) {
            if( v[i][j] == '*' ) {
                r = max( r, j );
                top = min( top, i );
                l = min( l, j );
                bottom = max( bottom, i );
            }
        }
    }
    for( int i = top; i <= bottom; i++ ) {
        for( int j = l; j <= r; j++ ) {
            cout << v[i][j];
        }
        cout << '\n';
    }
    return 0;
}