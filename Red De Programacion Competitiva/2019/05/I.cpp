#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long p1 = 11, p2 = 13;
    long long exp1 = 1, exp2 = 1;
    string s;
    cin >> s;
    long long left1 = 0, right1 = 0, left2 = 0, right2 = 0;
    int i = 0, j = s.size() - 1;
    int ans = 0;
    while(i <= j) {
        left1 = (left1 + ((s[i] - '0') * exp1) % mod) % mod;
        left2 = (left2 + ((s[i] - '0') * exp2) % mod) % mod;
        exp1 = (exp1*p1) % mod;
        exp2 = (exp2*p2) % mod;
        right1 = ((s[j] - '0') + (p1 * right1) % mod) % mod;
        right2 = ((s[j] - '0') + (p2 * right2) % mod) % mod;
        //cout << left1 << ' ' << right1 << ' ' << left2 << ' ' << right2 << '\n';
        if(left1 == right1 && left2 == right2) {
            left1 = right1 = left2 = right2 = 0;
            ans += (i == j)? 1 : 2;
            exp1 = 1;
            exp2 = 1;
            //cout << i << ' ' << j << '\n';
        }
        i++;
        j--;
    }
    //cout << left1 << ' ' << right1 << '\n';
    if(left1 != 0 || left2 != 0 || ans == 0) {
        ans++;
    }
    cout << ans << '\n';
    return 0;
}