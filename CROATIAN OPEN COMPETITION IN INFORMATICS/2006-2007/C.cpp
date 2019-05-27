#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    vector< vector<char> > v(5, vector <char> (1 + 4*s.size(), '.') );
    int x = 2;
    for(int i = 1; i <= s.size(); i++) {
        v[2][x] = s[i-1];
        for(int j = 0; j < 3; j++)  {
            int temp = (2-j);
            if(v[2 - temp][x+j] != '*') {
                v[2 - temp][x+j] = (i%3 == 0)? '*' : '#';
            }
            if(v[2 + temp][x+j] != '*') {
                v[2 + temp][x+j] = (i%3 == 0)? '*' : '#';
            }
            if(v[2 - temp][x-j] != '*') {
                v[2 - temp][x-j] = (i%3 == 0)? '*' : '#';
            }
            if(v[2 + temp][x-j] != '*') {
                v[2 + temp][x-j] = (i%3 == 0)? '*' : '#';
            }
        }
        x += 4;
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
    return 0;
}