#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        if(10 < s.size()) {
            cout << s[0] << s.size() - 2 << s[s.size()-1] << '\n';
        } else {
            cout << s << '\n';
        }
    }
    return 0;
}