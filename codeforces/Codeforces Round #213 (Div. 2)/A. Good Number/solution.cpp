#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans = 0;
    string s;
    char k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> s;
        int set = 0;
        for(char &i: s) {
            set |= (1<<(i-'0'));
        }
        if( (1<<(k-'0'+1)) - 1 == (set & ((1<<(k-'0'+1)) - 1)))
            ans++;
    }
    cout << ans << '\n';
    return 0;
}