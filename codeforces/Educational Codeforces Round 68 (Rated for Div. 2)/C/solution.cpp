#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin >> q;
    string s, t, p;
    while(q--) {
        cin >> s >> t >> p;
        bool ans = true;
        int i = 0, j = 0;
        map<char, int> m;
        for( char &i: p) {
            m[i]++;
        }
        int n = t.size();
        int tam = 0;
        for(int k = 0; k < n; k++) {
            if(i < s.size() && s[i] == t[k]) {
                i++;
                continue;
            } else {
                if(m[t[k]] == 0) {
                    ans = false;
                    break;
                } else {
                    tam++;
                    m[t[k]]--;
                }
            }
        }
        cout << ((ans && tam + s.size() == n)? "YES" : "NO") << '\n';
    }
    return 0;
}