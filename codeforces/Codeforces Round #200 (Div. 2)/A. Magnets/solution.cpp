#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string temp = "", s;
    int ans = 0;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(temp != s) {
            temp = s;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}