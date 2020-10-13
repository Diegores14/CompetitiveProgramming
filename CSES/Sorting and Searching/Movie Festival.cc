#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    ii v[n];
    for( int i = 0, a, b; i < n; i++ ) {
        cin >> a >> b;
        v[i] = ii(b, a);
    }
    sort( v, v+n);
    int pos = 0;
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
        if( pos <= v[i].second ) {
            pos = v[i].first;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}