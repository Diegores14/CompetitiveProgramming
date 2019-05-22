#include <bits/stdc++.h>
using namespace std;
const int tam = 10001;
int a, b, c, d, e, f;
int mod = 10000007;
long long memo[tam];

long long fn(int n) {
    if( memo[n] != -1) return memo[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    long long &ans = memo[n];
    return ans = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % mod;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int r = 1; r <= t; r++) {
        cin >> a >> b >> c >> d >> e >> f >> n;
        a %= mod;
        b %= mod;
        c %= mod;
        d %= mod;
        e %= mod;
        f %= mod;
        memset(memo, -1, sizeof memo);
        cout << "Case " << r << ": " << fn(n) << '\n';
    }
    return 0;
}