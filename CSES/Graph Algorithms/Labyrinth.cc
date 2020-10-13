#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char c[4] = {'D','U','R','L'};
char used[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string v[n];
    int x, y;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
        for( int j = 0; j < m; j++ ) {
            used[i][j] = 'X';
            if( v[i][j] == 'A' ) {
                x = i;
                y = j;
            }
        }
    }
    queue< ii > q;
    q.push(ii(x, y));
    used[x][y] = 'P';
    while( !q.empty() ) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if( v[x][y] == 'B' ) break; 
        for( int i = 0; i < 4; i++ ) {
            int tempx = x+dx[i];
            int tempy = y+dy[i];
            if( 0 <= tempx && 0 <= tempy && tempx < n && tempy < m && 
                used[tempx][tempy] == 'X' && v[tempx][tempy] != '#') {
                    used[tempx][tempy] = c[i];
                    q.push(ii(tempx, tempy));
            }
        }
    }
    string ans;
    if( v[x][y] != 'B' ) {
        cout << "NO\n";
        return 0;
    }
    while( used[x][y] != 'X' && used[x][y] != 'P' ) {
        ans += used[x][y];
        if( used[x][y] == 'U' ) {
            x += 1;
            continue;
        }
        if( used[x][y] == 'D' ) {
            x -= 1;
            continue;
        }
        if( used[x][y] == 'L' ) {
            y += 1;
            continue;
        }
        if( used[x][y] == 'R' ) {
            y -= 1;
            continue;
        }
    }
    reverse( ans.begin(), ans.end() );
    cout << "YES\n";
    cout << ans.size() << '\n';
    cout << ans << '\n';
    return 0;
}
