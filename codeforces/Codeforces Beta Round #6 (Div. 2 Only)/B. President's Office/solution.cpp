#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(char &j: v[i]) {
            cin >> j;
        }
    }
    set<char> se;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] != c && v[i][j] != '.') {
                if(i>0 && v[i-1][j] == c) {
                    se.insert(v[i][j]);
                }
                if(j>0 && v[i][j-1] == c) {
                    se.insert(v[i][j]);
                }
                if(j<m-1 && v[i][j+1] == c) {
                    se.insert(v[i][j]);
                }
                if(i<n-1 && v[i+1][j] == c) {
                    se.insert(v[i][j]);
                }
            }
        }
    }
    cout << se.size() << '\n';
    return 0;
}