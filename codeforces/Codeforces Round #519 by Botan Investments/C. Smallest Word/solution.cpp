#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0; i<n; i++) {
        if( (i+1 < n && s[i+1] == 'a') ^ (s[i] == 'a')) {
            cout << 1;
        } else {
            cout << 0;
        }
        cout << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}