#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> m >> n;
    vector < vector<char> > v(n, vector<char> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            cout << v[i][j] << v[i][j];
        }
        cout << '\n';
        for(int i=0; i<n; i++) {
            cout << v[i][j] << v[i][j];
        }
        cout << '\n';
    }
    return 0;
}