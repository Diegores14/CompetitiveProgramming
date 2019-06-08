#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s[2];
    int v[2];
    while(cin >> s[0] >> v[0] >> s[1] >> v[1]) {
        if(s[0] == s[1] ) {
            if(v[0] == v[1]) {
                cout << "Draw\n";
            } else {
                if(v[0] > v[1]) {
                    cout << "Tobby" << '\n';
                } else {
                    cout << "Naebbirac" << '\n';
                }
            }
            continue;
        }
        if((s[0][0] == 'B' || s[1][0] == 'B') && (s[0][0] == 'D' || s[1][0] == 'D')) {
            if(s[0][0] == 'B') {
                cout << ((2*v[0] <= v[1])? "Naebbirac" : "Tobby") << '\n';
            } else {
                cout << ((2*v[1] <= v[0])? "Tobby" : "Naebbirac") << '\n';
            }
        }
        if((s[0][0] == 'D' || s[1][0] == 'D') && (s[0][0] == 'C' || s[1][0] == 'C')) {
            if(s[0][0] == 'D') {
                cout << ((2*v[0] <= v[1])? "Naebbirac" : "Tobby") << '\n';
            } else {
                cout << ((2*v[1] <= v[0])? "Tobby" : "Naebbirac") << '\n';
            }
        }
        if((s[0][0] == 'B' || s[1][0] == 'B') && (s[0][0] == 'C' || s[1][0] == 'C')) {
            if(s[0][0] == 'C') {
                cout << ((2*v[0] <= v[1])? "Naebbirac" : "Tobby") << '\n';
            } else {
                cout << ((2*v[1] <= v[0])? "Tobby" : "Naebbirac") << '\n';
            }
        }
    }
    return 0;
}