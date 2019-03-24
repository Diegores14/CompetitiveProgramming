#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long double p = (long double)a/b, q = (1 - p) * (1 - (long double)c/d);
    long double ans = 1, temp = 1;
    for(int i=0; i<1000000; i++) {
        temp *= q;
        ans += temp;
    }
    cout << fixed << setprecision(15) << p * ans << '\n';
    return 0;
}