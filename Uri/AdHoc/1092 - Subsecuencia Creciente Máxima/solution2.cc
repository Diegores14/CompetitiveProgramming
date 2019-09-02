#include <bits/stdc++.h>
using namespace std;
const int tam = 605;
int v[tam][tam];
int ind[tam][tam];
int maxCol[tam];
int n, m;

int solve() {
    int ans = 0;
    for( int ini = 1; ini <= m; ini++ ) {
        for( int end = m; ini <= end; end-- ) {
            int len = end - ini + 1;
            if( maxCol[end] < len ) continue;
            if( len*n <= ans ) continue;
            int dp;
            if( ind[1][end] <= ini ) {
                dp = 1;
            } else { 
                dp = 0;
            }
            ans = max( ans, dp*len );
            for( int line = 2; line <= n; line++ ) {
                if( v[line-1][end] >= v[line][ini] ) {
                    dp = 0;
                }
                if( ind[line][end] <= ini ) {
                    dp++;
                } else {
                    dp = 0;
                }
                ans = max( ans, dp*len );
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while( cin >> n >> m, n || m ) {
        fill( maxCol, maxCol+m+1, 1 );
        for(int i = 1; i <= n; i++ ) {
            cin >> v[i][1];
            ind[i][1] = 1;
            for( int j = 2; j <= m; j++ ) {
                cin >> v[i][j];
                if( v[i][j-1] < v[i][j] ) {
                    ind[i][j] = ind[i][j-1];
                } else {
                    ind[i][j] = j;
                }
                maxCol[j] = max( maxCol[j], j - ind[i][j] + 1 );
            }
        }
        cout << solve() << '\n';
    }
    return 0;
}