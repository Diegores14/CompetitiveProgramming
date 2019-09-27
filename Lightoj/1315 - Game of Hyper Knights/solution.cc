#include <bits/stdc++.h>
using namespace std;
const int tam = 1005;
int v[tam][tam];
int dy[6] = {-2, -3, -2, -1, -1, 1};
int dx[6] = {1, -1, -1, -2, -3, -2};
bool used[8];

void precompute() {
    memset( v, 0, sizeof v );
    for( int i = 0; i < tam; i++ ) {
        int r = 0;
        for( int j = i; j >= 0; j-- ) {
            memset( used, 0, sizeof used );
            for( int k = 0; k < 6; k++ ) {
                int x = j+dx[k];
                int y = r+dy[k];
                if( 0 <= x && 0 <= y && x < tam && y < tam ) {
                    used[v[x][y]] = true;
                }
            }
            int k = 0; 
            while( used[k] ) k++;
            v[j][r] = k;
            r++;
        }
    }
}

void solve() {
    int n, x, y;
    cin >> n;
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
        cin >> x >> y;
        ans ^= v[x][y];
    }
    cout << ( ans? "Alice" : "Bob" ) << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    precompute();
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}
