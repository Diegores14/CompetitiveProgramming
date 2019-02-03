#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    set<char> s({'a','e','i', 'o', 'u'});
    cin >> s1 >> s2;
    if(s1.size() != s2.size()) {
        cout << "No\n";
    } else {
        for(int i=0; i<s1.size(); i++) {
            if(s.count(s1[i]) != s.count(s2[i])) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    }
    return 0;
}