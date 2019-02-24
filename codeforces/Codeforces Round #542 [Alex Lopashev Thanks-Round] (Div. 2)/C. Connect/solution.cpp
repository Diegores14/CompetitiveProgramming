#include <bits/stdc++.h>
using namespace std;
int n, r1, c1, r2, c2;
vector<vector<char>> v;

bool expand(int r, int c, int x, int y,char value) {
    queue< pair<int,int> > q;
    v[r][c] = value;
    q.push( make_pair(r,c) );
    while(!q.empty() && (q.front().first != x || q.front().second != y)) {
        pair<int,int> temp = q.front();
        q.pop();
        if(0 < temp.first && v[temp.first-1][temp.second] == '0' && v[temp.first-1][temp.second] == '0') {
            q.push( make_pair(temp.first-1, temp.second));
            v[temp.first-1][temp.second] = value;
        }
        if(0 < temp.second && v[temp.first][temp.second-1] == '0' && v[temp.first][temp.second-1] == '0') {
            q.push( make_pair(temp.first, temp.second-1));
            v[temp.first][temp.second-1] = value;
        }
        if(temp.first < n-1 && v[temp.first+1][temp.second] == '0' && v[temp.first+1][temp.second] == '0') {
            q.push( make_pair(temp.first+1, temp.second));
            v[temp.first+1][temp.second] = value;
        }
        if(temp.second < n-1 && v[temp.first][temp.second+1] == '0' && v[temp.first][temp.second+1] == '0') {
            q.push( make_pair(temp.first, temp.second+1));
            v[temp.first][temp.second+1] = value;
        }
    }
    return !q.empty();
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--;
    r2--;
    c1--;
    c2--;
    v.assign(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    if(expand(r1, c1, r2, c2, '2')) {
        cout << "0\n";
        return 0;
    }
    expand(r2, c2, -1, -1, '3');
    int ans = 1e9;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int x=0; x<n; x++) {
                for(int y=0; y<n; y++) {
                    if(v[i][j] == '2' && v[x][y] == '3') {
                        ans = min(ans, (i-x)*(i-x)+(j-y)*(j-y));
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}