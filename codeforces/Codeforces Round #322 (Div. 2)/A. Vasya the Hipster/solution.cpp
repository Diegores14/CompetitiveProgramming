#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b;
    cin >> a >> b;
    int mmin = min(a, b);
    a -= mmin;
    b -= mmin;
    cout << mmin << ' ' << (a+b)/2 << '\n';
    return 0;
}