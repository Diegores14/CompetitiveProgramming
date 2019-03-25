#include <bits/stdc++.h>
using namespace std;
int valores[255][255];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t, r, c;

int cantMax(list< pair<int,int> > q) {
    int mmax = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for(int i=0; i<4; i++) {
            if(0 <= x + dx[i] && x + dx[i] < r &&
                0 <= y + dy[i] && y + dy[i] < c &&
                valores[x+dx[i]][y+dy[i]] == -1) {
                    q.push_back( make_pair(x+dx[i], y+dy[i]) );
                    valores[x+dx[i]][y+dy[i]] = valores[x][y] + 1;
                    mmax = valores[x][y] + 1;
            }
        }
    }
    return mmax;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int k=1; k<=t; k++) {
        cin >> r >> c;
        cout << "Case #" << k << ": ";
        vector<string> v(r);
        for(string &i: v) {
            cin >> i;
        }
        list< pair<int,int> > q;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(v[i][j] == '1') {
                    q.push_back( make_pair(i, j) );
                }
            }
        }
        int ans = (int) 1e9;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(v[i][j] == '0') {
                    memset(valores, -1, sizeof valores);
                    q.push_back(make_pair(i, j));
                    for(auto &i: q) {
                        valores[i.first][i.second] = 0;
                    }
                    ans = min(ans, cantMax(q));
                    q.pop_back();
                }
            }
        }
        if(ans != 1e9)
            cout << ans << '\n';
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}