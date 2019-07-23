#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while(n >= m) {
        n -= m-1;
        ans += m;
    }
    cout << ans + n << '\n';
    return 0;
}