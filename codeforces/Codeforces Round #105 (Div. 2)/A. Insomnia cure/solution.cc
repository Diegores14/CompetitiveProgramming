#include <bits/stdc++.h>
using namespace std;
int v[4], d;

int gcd(int a, int b) {
    return b? gcd(b, a%b) : a;
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int solve(int idx, int mul, int par) {
    if(idx == 4) return 0;
    int ans = (d/lcm(mul, v[idx])) * (par? -1 : 1);
    ans += solve(idx+1, mul, par);
    ans += solve(idx+1, lcm(mul, v[idx]), par^1);
    return ans ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> v[0] >> v[1] >> v[2] >> v[3] >> d;
    cout << solve(0, 1, 0) << '\n';
    return 0;
}