#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    long long ans = 0;
    long long l = -1;
    long long n = s.size();
    for(int i=0;  i < (int)s.size()-3; i++) {
        if(s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r') {
            ans += (i-l)*(n-(i+3));
            l = i;
        }
    }
    cout << ans << '\n';
    return 0;
}