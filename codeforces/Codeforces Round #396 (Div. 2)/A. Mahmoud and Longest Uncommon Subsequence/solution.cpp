#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == s2) {
        cout << "-1\n";
    } else {
        cout << max(s1.size(), s2.size()) << '\n';
    }
    return 0;

}