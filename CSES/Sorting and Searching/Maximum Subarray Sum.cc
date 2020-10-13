#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    long long ans = -1e9, sum = 0;
    for( int i = 0; i < n; i++ ) {
        sum = max(sum+v[i], 0LL);
        ans = max( ans, v[i]);
        if( sum != 0 )
            ans = max(sum, ans);
    }
    cout << ans << '\n';
    return 0;
}