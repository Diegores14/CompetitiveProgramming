#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    list<char> l;
    for(int i=0; i<n; i++) {
        if((n-i)&1) {
            l.push_back(s[i]);
        } else {
            l.push_front(s[i]);
        }
    }
    for(char i: l) {
        cout << i;
    }
    cout << '\n';
    return 0;
}