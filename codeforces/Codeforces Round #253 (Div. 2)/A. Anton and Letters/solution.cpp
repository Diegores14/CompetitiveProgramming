#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    getline(cin, s);
    set<char> letters;
    if(2 < s.size())
    for(int i=1; i<s.size(); i+=3) {
        letters.insert(s[i]);
    }
    cout << letters.size() << '\n';

    return 0;
}