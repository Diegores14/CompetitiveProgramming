#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int i=0;
    while ( i < s.size() ) {
        if ( s[i] == '1' ) {
            i++;
            if ( i < s.size() && s[i] == '4' ) {
                i++;
                if ( i < s.size() && s[i] == '4' ) {
                    i++;
                }
            }
        } else {
            break;
        }
    }
    if ( i == s.size() ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}