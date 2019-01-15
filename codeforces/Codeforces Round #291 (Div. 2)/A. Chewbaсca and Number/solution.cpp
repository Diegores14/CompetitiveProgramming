#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    bool ans = false;
    for(int i=0; i<s.size(); i++) {
        s[i] = min(char('9'-s[i]+'0'), s[i]);
        if(ans) {
            cout << s[i];
        } else {
            if(s[i] == '0') {
                cout << '9';
            } else {
                cout << s[i];
            }
            ans = true;
        }
    }
    cout << '\n';
    return 0;
}