#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    set<char> se = {'1', 'l', 'L', 'i', 'I'}, se1 = {'0', 'O', 'o'};
    int n;
    cin >> s >> n;
    vector<string> v(n);
    bool ans = true;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        if(v[i].size() == s.size()) {
            bool flag = false;
            for(int j = 0; j<s.size(); j++) {
                if(!(tolower(v[i][j]) == tolower(s[j]) ||
                    (se.count(v[i][j]) && se.count(s[j])) ||
                    (se1.count(v[i][j]) && se1.count(s[j])) )){
                        flag = true;
                        break;
                }
            }
            ans &= flag;
        }
    }
    cout << (ans? "Yes\n" : "No\n");
    return 0;
}