#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
 
long long exp( long long b, int e ) {
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
    long long n;
    cin  >>  n;
    cout << exp(2, n) << '\n';
    return 0;
}
