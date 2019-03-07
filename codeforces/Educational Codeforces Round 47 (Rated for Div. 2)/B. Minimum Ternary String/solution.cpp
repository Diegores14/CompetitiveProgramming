#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int v[2] = {0, 0};
    int pos = -1;
    int l=0;
    for(char &i: s) {
        v[1] += (i == '1');
        if(pos == -1 && i == '2') {
            pos = l;
        }
        v[0] += (i == '0' && pos == -1);
        l++; 
    }
    while(v[0]--) {
        cout << 0;
    }
    while(v[1]--) {
        cout << 1;
    }
    for(int i=pos; i<s.size(); i++) {
        if(s[i] == '0' || s[i] == '2') {
            cout << s[i];
        }
    }
    cout << '\n';
    return 0;
}