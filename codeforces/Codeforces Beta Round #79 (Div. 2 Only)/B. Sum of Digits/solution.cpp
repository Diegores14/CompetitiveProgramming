#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    string s;
    cin >> s;
    int ans = 0;
    while(s.size() != 1) {
        int temp = 0;
        for(int i=0; i<s.size(); i++) {
            temp += s[i] - '0';
        }
        s = to_string(temp);
        ans++;
    }
    cout << ans << '\n';
    return 0;
}