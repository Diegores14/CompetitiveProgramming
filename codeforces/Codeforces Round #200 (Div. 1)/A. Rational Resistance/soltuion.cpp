#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return 0;
    return a/b + gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
    return 0;
}