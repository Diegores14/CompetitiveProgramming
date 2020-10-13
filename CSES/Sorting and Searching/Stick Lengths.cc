#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+7;
long long v[tam];
int n;
 
 
long long check( long long x ) {
    long long sum = 0;
    for( int i = 0; i < n; i++ ) {
        sum += abs(v[i]-x);
    }
    return sum;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    long long l = 0, r = 1e9+7;
    while( r-l > 2 ) {
        long long mid1 = l+(r-l)/3;
        long long mid2 = r-(r-l)/3;
        if( check(mid1) < check(mid2) ) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    long long ans = min( check(l), min(check(l+1), check(r)) );
    cout << ans << '\n';
    return 0;
}