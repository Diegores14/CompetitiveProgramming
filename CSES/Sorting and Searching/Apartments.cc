#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for( int i = 0; i < n; i++ ) {
        cin >> a[i];
    }
    for( int i = 0; i < m; i++ ) {
        cin >> b[i];
    }
    sort( a, a+n );
    sort( b, b+m );
    int pos = 0;
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
        while( pos < m && b[pos] < a[i]-k ) pos++;
        if( pos < m && a[i]-k <= b[pos] && b[pos] <= a[i]+k ) {
            ans++;
            pos++;
        }
    }
    cout << ans << '\n';
    return 0;
}
