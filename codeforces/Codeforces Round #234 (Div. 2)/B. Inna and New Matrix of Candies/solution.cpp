#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char temp;
    vector< vector<int> > v(n, vector<int> (2, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> temp;
            if(temp == 'G') {
                v[i][0] = j;
            }
            if(temp == 'S') {
                v[i][1] = j;
            }
        }
    }
    set<int> se;
    for(int i=0; i<n; i++) {
        if(v[i][0] > v[i][1]) {
            cout << "-1\n";
            return 0;
        }
        se.insert(v[i][0] - v[i][1]);
    }
    cout << se.size() << '\n';
    return 0;
}