#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case #" << k << ": ";
        string s;
        int n;
        cin >> n >> s;
        bool dir = (s[0] == 'S');
        bool dir1 = (s[s.size()-1] == 'S');
        vector< vector<bool> > v(2, vector<bool>(n, true));
        int x = 0, y = 0;
        for(char &i: s) {
            if(i == 'S') {
                v[1][y] = false;
                x++;
            } else {
                v[0][x] = false;
                y++;
            }
        }
        if( (dir && !dir1) ||  (!dir && dir1)) {
            for(int i=0; i<n-1; i++) {
                cout << (dir? 'E' : 'S');
            }
            for(int i=0; i<n-1; i++) {
                cout << (dir1? 'E' : 'S');
            }
        } else {
            x = 0;
            for(; x < n; x++) {
                if(v[dir][x]) {
                    for(int i=0; i<n-1; i++) {
                        cout << (dir? 'S' : 'E');
                    }
                    break;
                }
                cout << (dir? 'E' : 'S');
            }
            for(; x<n-1; x++) {
                cout << (dir? 'E' : 'S');
            }
        }
        cout << '\n';
    }
    return 0;
}