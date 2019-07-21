#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, c;
    cin >> a >> b >> c;
    long long mmax = 0;
    mmax = max(mmax, a*b*c);
    mmax = max(mmax, (a+b)*c);
    mmax = max(mmax, a+(b*c));
    mmax = max(mmax, (a*b)+c);
    mmax = max(mmax, a*(b+c));
    mmax = max(mmax, a+b+c);
    cout << mmax << '\n';
    return 0;
}