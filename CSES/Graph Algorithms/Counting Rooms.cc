#include <bits/stdc++.h>
using namespace std;
int cant = 0;
bool used[1000][1000];
typedef pair< int, int > ii;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
string v[1000];

void add( int x, int y ) {
    queue< ii > q;
    q.push(ii(x, y));
    cant++;
    used[x][y] = true;
    while( !q.empty() ) {
        int x_ = q.front().first;
        int y_ = q.front().second;
        q.pop();
        for( int i = 0; i < 4; i++ ) {
            int tempx = x_+dx[i];
            int tempy = y_+dy[i];
            if( 0 <= tempx && tempx < n && 0 <= tempy && tempy < m && !used[tempx][tempy] && v[tempx][tempy] == '.' ) {
                q.push( ii(tempx, tempy) );
                used[tempx][tempy] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    for( int i = 0; i < n; i++  ) {
        for( int j = 0; j < m; j++ ) {
            if( !used[i][j] && v[i][j] == '.' ) {
                add(i, j);
            }
        }
    }
    cout << cant << '\n';
    return 0;
}