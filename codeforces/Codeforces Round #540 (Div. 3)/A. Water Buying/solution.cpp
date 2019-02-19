#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long q, n, a, b;
    cin >> q;
    while(q--) {
        cin >> n >> a >> b;
        cout << min(n*a, (n>>1)*b + ((n&1)? a : 0)) << '\n';
    }
    return 0;
}