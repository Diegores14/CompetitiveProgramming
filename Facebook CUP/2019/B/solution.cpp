#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    for(int cases = 1; cases <= n; cases++) {
        cin >> s;
        int len = s.size();
        len -= 1;
        int cant = 0;
        for(char c: s) {
            if(c == 'B') cant++;
        }
        cout << "Case #" << cases << ": " << (((2 <= cant || (cant == 1 && len == 2)) && cant != len)? "Y" : "N") << '\n';
    }
    return 0;
}