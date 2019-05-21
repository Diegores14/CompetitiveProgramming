#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int x, y;
string v[21];
bool used[21][21];
int t, w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve() {
    queue< ii > q;
    int answer = 1;
    q.push({x, y});
    used[x][y] = true;
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            int tempx = temp.first + dx[i];
            int tempy = temp.second + dy[i];
            if(0 <= tempx && tempx < h && 0 <= tempy && tempy < w && !used[tempx][tempy] && v[tempx][tempy] == '.') {
                q.push({tempx, tempy});
                used[tempx][tempy] = true;
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> w >> h;
        cout << "Case " << r << ": ";
        for(int i=0; i<h; i++) {
            cin >> v[i];
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(v[i][j] == '@') {
                    x = i; 
                    y = j;
                    break;
                }
            }
        }
        memset(used, 0, sizeof used);
        cout << solve() << '\n';
    }
    return 0;
}