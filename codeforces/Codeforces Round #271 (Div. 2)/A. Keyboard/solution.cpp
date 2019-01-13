#include <bits/stdc++.h>
using namespace std;

void sol(string &s, vector<char> &v, map<char, int> &m, int add) {
    for(int i=0; i<s.size(); i++) {
        s[i] = v[m[s[i]] + add];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<char> v({'q','w','e','r','t','y','u','i','o','p',
                    'a','s','d','f','g','h','j','k','l',';',
                    'z','x','c','v','b','n','m',',','.','/'});
    map<char, int> m;
    for(int i=0; i<v.size(); i++) {
        m[v[i]] = i;
    }
    char c;
    string s;
    cin >> c >> s;
    if(c == 'R') {
        sol(s, v, m, -1);
    } else {
        sol(s, v, m, 1);
    }
    cout << s << '\n';
    return 0;
}