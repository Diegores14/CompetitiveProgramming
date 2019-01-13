#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> se;
    for(int i=0; i<n; i++) {
        se.insert(tolower(s[i]));
    }
    if(se.size() == 26) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}