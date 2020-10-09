#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;

long long exp( long long b, long long e, long long mod ) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans*b)%mod;
        }
        b = (b*b)%mod;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    while( n-- ) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << exp( a, exp(b, c, mod-1), mod ) << '\n';
    }
    return 0;
}