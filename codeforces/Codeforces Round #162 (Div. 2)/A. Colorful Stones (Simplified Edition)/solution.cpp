#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 1;
    for(char i: s2) {
        if(ans <= s1.size() && s1[ans-1] == i)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}