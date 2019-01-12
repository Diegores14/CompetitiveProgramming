#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, x;
    cin >> n >> x;
    char c;
    int temp, ans = 0;
    for(int i=0; i<n; i++) {
        cin >> c >> temp;
        if( c == '+') {
            x += temp;
        } else {
            if( temp <= x ) {
                x -= temp;
            } else {
                ans++;
            }
        }
    }
    cout << x << ' ' << ans << '\n';
    return 0;
}