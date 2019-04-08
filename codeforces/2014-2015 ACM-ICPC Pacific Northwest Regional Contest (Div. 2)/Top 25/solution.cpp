#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n;
        set< string > m;
        int temp = 0;
        int ans = -1;
        bool flag = true;
        vector< vector<string> > v(2, vector<string> (n));
        for(string &i: v[0]) {
            cin >> i;
        }
        for(string &i: v[1]) {
            cin >> i;
        }
        for(int i=0; i<n; i++) {
            temp++;
            m.insert(v[0][i]);
            m.insert(v[1][i]);
            if(m.size() == i-ans) {
                cout << (flag? "" : " ") << m.size();
                m.clear();
                flag = false;
                ans = i;
            }
        }
        cout << '\n';
    }
    return 0;
}