#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, t, temp, x;
    cin >> n >> t;
    pair< double, double > v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> x >> temp;
        v[i].first = x - double(temp)/2;
        v[i].second = x + double(temp)/2;
    }
    sort( v, v+n );
    int ans = 2;
    for( int i = 1; i < n; i++ ) {
        //cout << v[i].first << ' ' << v[i-1].second << '\n';
        if( v[i].first - v[i-1].second > t ) {
            ans += 2;
        }
        if( v[i].first - v[i-1].second == t ) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}