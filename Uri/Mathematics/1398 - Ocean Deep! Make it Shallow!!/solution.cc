#include <bits/stdc++.h>
using namespace std;
const int mod = 131071;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n = s.size();
    int sum = 0;
    bool flag = false;
    while(cin >> s) {
        //cout << s << '\n';
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '#') {
                flag = true;
                break;
            }
            sum = 2*sum + s[i] - '0';
            sum %= mod;
        }
        if(flag) {
            cout << (sum? "NO" : "YES") << '\n';
            flag = false;
            sum = 0;
        }
    }
    return 0;
}