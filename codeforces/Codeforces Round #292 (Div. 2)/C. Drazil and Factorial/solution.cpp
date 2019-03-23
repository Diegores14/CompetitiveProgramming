#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n;
    cin >> n;
    map<char, vector<int> > m;
    m['4'] = vector<int>({3, 2, 2});
    m['8'] = vector<int>({7, 2, 2, 2});
    m['6'] = vector<int>({5, 3});
    m['9'] = vector<int>({7, 3, 3, 2});
    vector<int> ans(10, 0);
    cin >> s;
    for(char &i: s) {
        if( m.count(i) ) {
            for(int &j: m[i]) {
                ans[j]++;
            }
        } else {
            ans[i - '0']++;
        }
    }
    for(int i=9; i>1; i--) {
        for(int j=0; j<ans[i]; j++) {
            cout << i;
        }
    }
    cout << '\n';
    return 0;
}