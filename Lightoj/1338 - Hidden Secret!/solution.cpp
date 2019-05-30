#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int v[2][26];
    string s1, s2;
    cin >> t;
    cin.ignore();
    for( int cases = 1; cases <= t; cases++ ) {
        getline(cin, s1);
        getline(cin, s2);
        memset(v, 0, sizeof v);
        for(char &i: s1) {
            if( i != ' ') {
                i = tolower(i);
                v[0][i - 'a']++;
            }
        }
        for(char &i: s2) {
            if( i != ' '){
                i = tolower(i);
                v[1][i - 'a']++;
            }
        }
        bool ans1 = true, ans2 = true;
        for(int i = 0; i < 26; i++) {
            if(v[0][i] < v[1][i]) {
                ans1 = false;
            }
            if(v[0][i] > v[1][i]) {
                ans1 = false;
            }
        }
        cout << "Case " << cases << ": " << ((ans1 && ans2)? "Yes\n" : "No\n");
    }
    return 0;
}