#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;

void solve( ) {
    int n;
    cin >> n;
    vector< ii > v(n);
    vector< ii > m;
    for( int i = 0 ; i < n; i++ ) {
        cin >> v[i].first >> v[i].second;
        for( int j = 0; j < i; j++ ) {
            m.push_back( ii(v[i].first + v[j].first, v[i].second + v[j].second) );
        }
    }
    sort( m.begin(), m.end() );
    int ans = 0, count = 1;
    for( int i = 1; i < m.size(); i++ ) {
        if( m[i] == m[i-1]) {
            count++;
        } else {
            ans += ( (count - 1)*(count) )/2;
            count = 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}