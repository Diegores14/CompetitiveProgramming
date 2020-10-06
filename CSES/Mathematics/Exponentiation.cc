#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
 
long long exp( long long b, long long e) {
    long long ans = 1;
    while( e ) {
        if( e&1 ) {
            ans = (ans*b)%mod;
        }
        e >>= 1;
        b = (b*b)%mod;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while( t-- ) {
        long long a, b;
        cin >> a >> b;
        cout << exp(a, b)  << '\n';
    }
    return 0;
}
