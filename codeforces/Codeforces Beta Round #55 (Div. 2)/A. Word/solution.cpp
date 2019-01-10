#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int cont1 = 0, cont2 = 0;
    cin >> s;
    for(char i: s) {
        if('a' <= i && i <= 'z') {
            cont1++;
        } else {
            cont2++;
        }
    }
    if(cont1 >= cont2) {
        for(char i: s) {
            cout << (char)tolower(i);
        }
    } else {
        for(char i: s) {
            cout << (char)toupper(i);
        }
    }
    cout << '\n';
    return 0;
}