#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y, x1, x2, y1, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(3);
    if(x1 <= x && x <= x2) {
        cout << (long double)min(abs(y1-y), abs(y2-y)) << '\n';
        return 0;
    }
    if(y1 <= y && y <= y2) {
        cout << (long double)min(abs(x1-x), abs(x2-x)) << '\n';
        return 0;
    }
    int a = min(abs(x-x1), abs(x-x2));
    int b = min(abs(y-y1), abs(y-y2));
    cout << (long double)sqrt(a*a + b*b) << '\n';
    return 0;
}