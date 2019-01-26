#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin >> n, n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += i*i;
        }
        cout << ans << '\n';
    }
    return 0;
}