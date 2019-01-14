#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(char &i: s) {
        if(i == '1') {
            ans++;
        } else {
            ans--;
        }
    }
    cout << abs(ans) << '\n';
    return 0;
}