#include <bits/stdc++.h>
using namespace std;

int leapYear(int y) {
    int ans = 0;
    ans += y/4;
    ans -= y/100;
    ans += y/400;
    return ans;
}

int isLeap(int y) {
    return (y%4 == 0 && y%100) || y%400 == 0;
}

int main() {
    int t;
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
    string s1, s2;
    char c;
    int d1, d2, y1, y2;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        cout << "Case " << k << ": ";
        cin >> s1 >> d1 >> c >> y1 >> s2 >> d2 >> c >> y2;
        int sum2 = leapYear(y2-1);
        int sum1 = leapYear(y1-1);
        if( m[s2] > 1 || (m[s2] == 1 && d2 == 29) ) {
            sum2 += isLeap(y2);
        }
        if( 1 < m[s1] ) {
            sum1 += isLeap(y1);
        }
        cout << sum2 - sum1 << '\n';
    }
    return 0;
}