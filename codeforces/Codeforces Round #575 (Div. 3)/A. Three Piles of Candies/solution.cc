#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long q, a, b, c;
    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        cout << (a + b + c)/2 << '\n';
    }
    return 0;
}