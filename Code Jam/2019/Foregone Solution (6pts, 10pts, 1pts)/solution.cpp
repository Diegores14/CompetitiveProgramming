#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int t;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cin >> s;
        vector< bool > v(s.size());
        cout << "Case #" << k << ": ";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '4') {
                cout << '2';
            } else {
                cout << s[i];
            }
            v[i] = (s[i] == '4');
        }
        cout << ' ';
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            if(v[i]) {
                flag = true;
            }
            if(flag) {
                cout << (v[i]? '2': '0');
            }
        }
        cout << '\n';
    }
    return 0;
}