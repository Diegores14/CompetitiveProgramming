#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+3;
long long sumRow[tam], sumCol[tam];


bool orderRow( int i, int j ) {
    return sumRow[i] > sumRow[j];
}

bool orderCol( int i, int j ) {
    return sumCol[i] > sumCol[j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int v[n][m];
    memset( sumCol, 0, sizeof sumCol );
    memset( sumRow, 0, sizeof sumRow );
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
            cin >> v[i][j];
            sumRow[i] += v[i][j]; 
            sumCol[j] += v[i][j];
        }
    }
    int posRow[n], posCol[m];
    for( int i = 0; i < n; i++) posRow[i] = i;
    for( int i = 0; i < m; i++) posCol[i] = i;
    sort( posCol, posCol+m, orderCol );
    sort( posRow, posRow+n, orderRow );
    long long sum = 0;
    for( int i = 0; i < 4 && i < n; i++ ) {
        sum += sumRow[posRow[i]];
    }
    long long ans = sum;
    sum = 0;
    for( int i = 0; i < 4 && i < m; i++ ) {
        sum += sumCol[posCol[i]];
    }
    ans = max( ans, sum );
    for( int i = 0; i < 8 && i < n; i++ ) {
        for( int j = i+1; j < 8 && j < n; j++ ) {
            for( int k = j+1; k < 8 && k < n; k++) {
                for( int r = 0; r < 8 && r < m; r++ ) {
                    sum = sumRow[posRow[i]] + sumRow[posRow[j]] + sumRow[posRow[k]] + sumCol[posCol[r]] - v[posRow[i]][posCol[r]] - v[posRow[j]][posCol[r]] - v[posRow[k]][posCol[r]];
                    ans = max(ans, sum);
                }
            }
        }
    } 
    for( int i = 0; i < 8 && i < m; i++ ) {
        for( int j = i+1; j < 8 && j < m; j++ ) {
            for( int k = j+1; k < 8 && k < m; k++) {
                for( int r = 0; r < 8 && r < n; r++ ) {
                    sum = sumCol[posCol[i]] + sumCol[posCol[j]] + sumCol[posCol[k]] + sumRow[posRow[r]] - v[posRow[r]][posCol[i]] - v[posRow[r]][posCol[j]] - v[posRow[r]][posCol[k]];
                    ans = max(ans, sum);
                }
            }
        }
    } 
    for( int i = 0; i < 8 && i < m; i++ ) {
        for( int j = i+1; j < 8 && j < m; j++ ) {
            for( int k = 0; k < 8 && k < n; k++) {
                for( int r = k+1; r < 8 && r < n; r++ ) {
                    sum = sumCol[posCol[i]] + sumCol[posCol[j]] + sumRow[posRow[k]] + sumRow[posRow[r]] - v[posRow[r]][posCol[i]] - v[posRow[r]][posCol[j]] - v[posRow[k]][posCol[i]] - v[posRow[k]][posCol[j]];
                    ans = max(ans, sum);
                }
            }
        }
    } 
    cout << ans << '\n';
    return 0;
}