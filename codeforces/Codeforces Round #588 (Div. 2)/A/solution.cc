#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if( a+b == c+d || a+c == b+d || a+d == c+b || a == b+c+d || b == a+c+d  || c == a+b+d || d == a+b+c) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}