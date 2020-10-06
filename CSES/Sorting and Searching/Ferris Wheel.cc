#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, x;
    cin >> n >> x;
    int p[n];
    for( int i = 0; i < n; i++ ) {
        cin >> p[i];
    }
    sort( p, p+n );
    int l = 0, r = n-1;
    int ans = 0;
    while( l <= r ) {
        if( p[l]+p[r] <= x ) {
            l++;
        }
        ans++;
        r--;
    }
    cout << ans << '\n';
    return 0;
}
