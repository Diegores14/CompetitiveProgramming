#include <bits/stdc++.h>
using namespace std;
const int tam = 55;
int dp[tam][tam];
int arr[tam][tam];
int grundy[tam][tam];
int num[tam];
int g[tam];
typedef pair< int, int > ii;

int dfs( int now, int l, int r ) {
    if( r < l ) return 0;
    if( l == r ) return 1;
    if( dp[l][r] != -1 ) return dp[l][r];
    bool visit[tam];
    memset( visit, 0, sizeof visit );
    for( int i = l; i <= r; i++ ) {
        int next = -1, temp = 0;
        for( int j = l; j <= r; j++ ) {
            if( arr[now][j] < arr[now][i] ) {
                next = j; break;
            }
        }
        for( int j = next+1; j <= r && next != -1; j++ ) {
            if( arr[now][j] >= arr[now][i] ) {
                temp ^= dfs( now, next, j-1 );
                next = -1;
                for( int k = j+1; k <= r; k++ ) {
                    if( arr[now][k] < arr[now][i] ) {
                        next = j = k;
                        break;
                    }
                }
            }
        }
        if( next != -1 ) temp ^= dfs( now, next, r );
        visit[temp] = true;
        if( l == 0 && r == num[now]-1 ) grundy[now][i] = temp;
    }
    int k = 0; 
    while( visit[k] ) k++;
    dp[l][r] = k;
    return dp[l][r];
}

void solve() {
    int n; 
    cin >> n;
    int ans = 0; 
    for( int i = 0; i < n; i++ ) {
        memset( dp, -1, sizeof dp);
        cin >> num[i];
        for( int j = 0; j < num[i]; j++ ) {
            cin >> arr[i][j];
        }
        g[i] = dfs(i, 0, num[i]-1);
        ans ^= g[i];
    }
    if( ans ) {
        cout << "Aladdin\n";
        set< ii > output;
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < num[i]; j++ ) {
                if( (ans^g[i]^grundy[i][j]) == 0 ) {
                    output.insert( ii(i, arr[i][j]) );
                }
            }
        }
        for( ii i: output ) {
            cout << "(" << i.first+1 << ' ' << i.second << ")";
        }
        cout << '\n';
    } else {
        cout << "Genie\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}