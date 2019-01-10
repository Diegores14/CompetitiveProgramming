#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans = 0;
    char c, temp = 'a';
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c;
        if(temp != c) {
            temp = c;
        } else {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}