#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    cout << (char)toupper(s[0]);
    for(int i=1; i<s.size(); i++) {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}