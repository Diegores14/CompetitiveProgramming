#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = (m > 1? m-1 : m+1);
    if( m+1 <= n && n - m >= m ) {
        ans = m+1;
    }
    if( m-1 > 0 && m-1 >= n - (m-1) ) {
        ans = m-1;
    }
    cout << ans << '\n';
    return 0;
}