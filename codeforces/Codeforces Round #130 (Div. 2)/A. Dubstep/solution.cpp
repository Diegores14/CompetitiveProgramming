#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, temp = "";
    cin >> s;
    vector<string> v;
    int i=0;
    while(i<s.size()) {
        if(i+2 < s.size() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            if(temp != "") {
                v.emplace_back(temp);
                temp = "";
            }
            i+=3;
        } else {
            temp.push_back(s[i]);
            i++;
        }
    }
    if(temp != "") {
        v.emplace_back(temp);
    }
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << ((v.size() - 1 == i)? '\n' : ' ');
    }
    return 0;
}