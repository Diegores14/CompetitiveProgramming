#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int tam = 51;
int timeLava[tam][tam];
int dp[tam][tam];
int mov[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp, -1, sizeof dp);
    memset(timeLava, -1, sizeof timeLava);
    int n, m, sx, sy, dx, dy;
    cin >> n >> m;
    string v[n];
    for(string &i: v) {
        cin >> i;
    }
    queue< ii > q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '*') {
                timeLava[i][j] = 0;
                q.push( {i, j} );
            }
            if(v[i][j] == 'D') {
                dx = i, dy = j;
            }
            if(v[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++) {
            int _x = x + mov[i][0];
            int _y = y + mov[i][1];
            if(0 <= _x && _x < n && 0 <= _y && _y < m 
                && timeLava[_x][_y] == -1 && v[_x][_y] != 'D' && v[_x][_y] != 'X') {
                    q.push({_x, _y});
                    timeLava[_x][_y] = timeLava[x][y] + 1;
                }
        }
    }
    q.push({sx, sy});
    dp[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++) {
            int _x = x + mov[i][0];
            int _y = y + mov[i][1];
            int ans = dp[x][y] + 1;
            if(0 <= _x && _x < n && 0 <= _y && _y < m 
                && dp[_x][_y] == -1 && (ans < timeLava[_x][_y] 
                || timeLava[_x][_y] == -1) && v[_x][_y] != 'X') {
                    q.push({_x, _y});
                    dp[_x][_y] = ans;
                }
        }
    }
    if( dp[dx][dy] == -1 ) {
        cout << "KAKTUS\n";
    } else {
        cout << dp[dx][dy] << '\n';
    }
    return 0;
}