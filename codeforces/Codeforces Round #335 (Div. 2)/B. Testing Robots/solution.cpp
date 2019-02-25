#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    string s;
    cin >> s;
    vector< vector<bool> > used(n, vector<bool> (m, false));
    int cont = 0;
    for(int i=0; i<s.size(); i++) {
        if(!used[x][y]) {
            cout << 1 << ' ';
            cont++;
            used[x][y] = true;
        } else {
            cout << 0 << ' ';
        }
        if(s[i] == 'U' && 0<x) {
            x--;
        }
        if(s[i] == 'D' && x<n-1) {
            x++;
        }
        if(s[i] == 'R' && y<m-1) {
            y++;
        }
        if(s[i] == 'L' && 0<y) {
            y--;
        }
    }
    cout << n*m - cont << '\n';
    return 0;
}