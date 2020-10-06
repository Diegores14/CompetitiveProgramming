#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    sort( v, v+n );
    int ans = 1;
    for( int i = 1; i < n; i++ ) {
        if( v[i] != v[i-1] ) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
