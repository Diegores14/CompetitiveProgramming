#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    set<char> se({'A', 'O', 'Y', 'E', 'U', 'I'});
    string s;
    cin >> s;
    for(char &i: s) {
        if(se.count(toupper(i)) == 0){
            cout << "." << (char)tolower(i);
        }
    }
    cout << '\n';
    return 0;
}