#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    int match = 0, notmatch = 0;
    string s1, s2;
    cin >> k >> s1 >> s2;
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] == s2[i]) {
            match++;
        } else {
            notmatch++;
        }
    }
    int ans = 0;
    if(k <= match) {
        ans += k;
    } else {
        ans += match;
    }
    if(s1.size() - k <= notmatch) {
        ans += s1.size() - k;
    } else {
        ans += notmatch;
    }
    cout << ans << '\n';
    return 0;
}