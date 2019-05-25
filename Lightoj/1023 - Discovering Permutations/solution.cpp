#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    char v[26];
    for(char i = 'A'; i <= 'Z'; i++) {
        v[i-'A'] = i;
    }
    int t, n, k;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n >> k;
        cout << "Case " << cases << ":\n";
        do {
            for(int i = 0; i < n; i++) {
                cout << v[i];
            }
            cout << '\n';
        } while(next_permutation(v, v+n) && --k);
        for(char i = 'A'; i < 'A'+n; i++) {
            v[i-'A'] = i;
        }
    }
    return 0;
}