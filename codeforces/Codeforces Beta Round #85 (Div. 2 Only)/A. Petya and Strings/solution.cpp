#include <bits/stdc++.h>
using namespace std;

void lower(string &s) {
    for(char &i: s) {
        i = tolower(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    lower(s1);
    lower(s2);
    if(s1 == s2) {
        cout << "0\n";
    } else {
        if(s1 < s2) {
            cout << "-1\n";
        } else {
            cout << "1\n";
        }
    }
    return 0;
}