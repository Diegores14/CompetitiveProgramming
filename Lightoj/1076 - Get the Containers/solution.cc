#include <bits/stdc++.h>
using namespace std;
const int tam = 1005;
int t, n, m;
int v[tam];

bool check( int x ) {
    int ans = 1, acc = 0;
    for( int i = 0; i < n; i++ ) {
        if( acc + v[i] <= x ) {
            acc += v[i];
        } else {
            if( v[i] > x ) return false;
            ans++;
            acc = v[i];
        }
    }
    return ans <= m;
}
 
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ )  {
        cin >> n >> m;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i];
        }
        int l = 0, r = 1e9+7;
        while( r-l != 1 ) {
            int mid = l+(r-l)/2;
            if( check(mid) ) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << "Case " << cases << ": " << r << '\n';
    }
    return 0;
}