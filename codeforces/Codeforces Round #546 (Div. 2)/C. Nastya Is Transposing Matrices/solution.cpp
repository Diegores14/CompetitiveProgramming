#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, temp;
    cin >> n >> m;
    map< int, int> row[n+m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            row[i+j][temp]++;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            row[i+j][temp]--;
        }
    }
    bool ans = true;
    for(int i=0; i<n+m && ans; i++) {
        for(auto &j: row[i]) {
            if(j.second) {
                ans = false;
                break;
            }
        }
    }
    cout << (ans? "YES\n" : "NO\n");
    return 0;
}