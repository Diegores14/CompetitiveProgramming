#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v(4);
    long long ans = 0;
    string s;
    for(int &i: v) {
        cin >> i;
    }
    cin >> s;
    for(char i: s) {
        ans += v[i-'1'];
    }
    cout << ans << '\n';
    return 0;
}