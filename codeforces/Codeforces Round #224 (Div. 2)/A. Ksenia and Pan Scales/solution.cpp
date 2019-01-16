#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s1, s2, s3;
    getline(cin, s1, '|');
    getline(cin, s2);
    getline(cin, s3);
    for(int i=0; i<s3.size(); i++) {
        if(s1.size() < s2.size()) {
            s1 = s3[i] + s1;
        } else {
            s2.push_back(s3[i]);
        }
    }
    if(s1.size() == s2.size()) {
        cout << s1 << '|' << s2 << '\n';
    } else {
        cout << "Impossible\n";
    }
    return 0;
}