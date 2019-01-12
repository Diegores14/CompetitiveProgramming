#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int ans = 0, temp;
    string s; 
    cin >> s;
    int i=0, n = s.size();
    for (; i<n; i++) {
        if(s[i] == '[') {
            ans ++;
            break;
        }
    }
    for(; i<n; i++){
        if(s[i] == ':'){
            ans++;
            break;
        }
    }
    int j = n-1;
    for(; j>=0; j--) {
        if(s[j] == ']') {
            ans ++;
            break;
        }
    }
    for(; j>=0; j--) {
        if(s[j] == ':') {
            ans ++;
            break;
        }
    }
    if(i<j) {
        for(; i<j; i++) {
            if(s[i] == '|') {
                ans++;
            }
        }
        cout << ans << '\n';
    }else {
        cout << "-1\n";
    }
    return 0;
}