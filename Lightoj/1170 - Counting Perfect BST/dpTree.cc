#include <bits/stdc++.h>
using namespace std;

int solve( int l, int r ) {
    if( r <= l ) return 1;
    int ans = 0;
    for( int i = l; i <= r; i++ ) {
        ans += solve( l, i-1 )*solve( i+1, r );
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve( 1, n ) << '\n';
    return 0;
}