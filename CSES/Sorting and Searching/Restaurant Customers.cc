#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<ii> v;
    for( int i = 0, a, b; i < n; i++ ) {
        cin >> a >> b;
        v.push_back(ii(a, 1));
        v.push_back(ii(b, -1));
    }
    sort( v.begin(), v.end());
    int pos = 0;
    int ans = 0, sum = 0;
    for( auto i: v ) {
        sum += i.second;
        ans = max( ans, sum );
    }
    cout << ans << '\n';
    return 0;
}