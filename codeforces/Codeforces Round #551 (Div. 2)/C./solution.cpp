#include <bits/stdc++.h>
using namespace std;

bool check(string &s) {
    int ans = 0;
    int n = s.size();
    for(int i=1; i < n-1; i++) {
        if(s[i] == ')') {
            ans--;
        } else {
            ans++;
        }
        if(ans < 0) {
            break;
        }
    }
    return ans == 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n, cont1 = 0, cont2 = 0;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') {
            cont1++;
        }
        if(s[i] == ')') {
            cont2++;
        }
    }
    cont1 = n/2 - cont1;
    cont2 = n/2 - cont2;
    for(int i=0; i<n && cont1 > 0; i++) {
        if(s[i] == '?') {
            s[i] = '(';
            cont1--;
        }
    }
    for(int i=0; i<n && cont2 > 0; i++) {
        if(s[i] == '?') {
            s[i] = ')';
            cont2--;
        }
    }
    if(!check(s) || n&1 || s[0] == ')' || s[n-1] == '(') {
        cout << ":(\n";
    } else {
        cout << s << '\n';
    }
    return 0;
}