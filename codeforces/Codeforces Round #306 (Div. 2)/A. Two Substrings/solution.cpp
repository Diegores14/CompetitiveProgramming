#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size(); 
    vector< vector<int> > v(2);
    for(int i=0; i < n-1; i++) {
        if(s[i] == 'A' && s[i+1] == 'B') {
            v[0].emplace_back(i);
        }
        if(s[i] == 'B' && s[i+1] == 'A') {
            v[1].emplace_back(i);
        }
    }
    for(int &i: v[0]) {
        for(int &j: v[1]) {
            if(abs(i-j) > 1) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}