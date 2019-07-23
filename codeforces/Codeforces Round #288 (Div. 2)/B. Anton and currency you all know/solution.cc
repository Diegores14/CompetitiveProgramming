#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    int first = -1;
    int n = s.size();
    for(int i = 0; i < n-1; i++) {
        if((s[i] - '0')%2 == 0) {
            first = i;
            if(s[i] < s[n-1]) {
                break;
            }
        }
    }
    if(first != -1) {
        swap(s[first], s[n-1]);
        cout << s << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}