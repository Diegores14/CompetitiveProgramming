#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<string, int> m;
    m["January"] = 0;
    m["February"] = 1;
    m["March"] = 2;
    m["April"] = 3;
    m["May"] = 4;
    m["June"] = 5;
    m["July"] = 6;
    m["August"] = 7;
    m["September"] = 8;
    m["October"] = 9;
    m["November"] = 10;
    m["December"] = 11;
    string s, s1;
    char c;
    int d, d1, y, y1;
    cin >> n;
    for(int k=1; k<=n; k++) {
        cout << "Case " << k << ": ";
        cin >> s >> d >> c >> y >> s1 >> d1 >> c >> y1;
        int ans = y1/4 - y1/100 + y1/400;
        ans -= (y-1)/4 - (y-1)/100 + (y-1)/400;
        if((y%100 == 0 || (y%4 == 0 && y%100)) && m[s] > 1) {
            ans--;
        }
        if((y1%100 == 0 || (y1%4 == 0 && y1%100)) && (m[s1] == 0 || (m[s1] == 1 && d1<29))) {
            ans--;
        }
        if(y1 == y && m[s] == m[s1] && d1 == d && d == 29 && m[s] == 1) {
            ans = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}