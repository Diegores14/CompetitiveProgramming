#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    bool ans = true;
    cin >> n;
    map<char, int> m;
    vector< vector<char> > v(n, vector<char>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
            m[v[i][j]]++;
        }
    }
    for(int i=0; i<n; i++) {
        if(v[i][i] != v[0][0] || v[i][n-i-1] != v[0][0]) {
            ans = false;
            break;
        }
    }
    if(m.size() == 2 && ans) {
        for(auto i: m) {
            if(i.second != ((n<<1)-1) && i.second != (n*n-(n<<1)+1)) {
                ans = false;
            }
        }
        cout << (ans? "YES\n" : "NO\n");
    } else {
        cout << "NO\n";
    }
    return 0;
}