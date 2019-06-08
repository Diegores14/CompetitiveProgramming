#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    set<char> vowels({'a', 'e', 'i', 'o', 'u'});
    string s;
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin, s);
        for(char &i: s) {
            if(vowels.count(i)) {
                cout << i << 'p';
            }
            cout << i;
        }
        cout << '\n';
    }
    return 0;
}