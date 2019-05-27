#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double r;
    cin >> r;
    cout << fixed << setprecision(6) << PI*r*r << '\n' << 2*r*r << '\n';
    return 0;
}