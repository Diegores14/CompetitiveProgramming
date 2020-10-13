#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    ii v[n];
    for( int i = 0, a, b; i < n; i++ ) {
        cin >> a ;
        v[i] = ii(a, i+1);
    }
    sort( v, v+n );
    int l = 0, r = n-1;
    while( l < r ) {
        if( v[l].first+v[r].first == x ) {
            cout << v[l].second << ' ' << v[r].second << '\n';
            return 0;
        }
        if( v[l].first+v[r].first > x ) {
            r--;
        } else {
            l++;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}