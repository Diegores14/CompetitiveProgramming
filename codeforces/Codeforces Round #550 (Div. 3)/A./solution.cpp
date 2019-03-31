#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        sort(s.begin(), s.end());
        bool ans = true;
        for(int i=1; i<s.size(); i++) {
            if(s[i-1] != s[i] - 1) {
                ans = false;
                break;
            }
        }
        cout << (ans? "Yes\n" : "No\n");
    }
    return 0;
}