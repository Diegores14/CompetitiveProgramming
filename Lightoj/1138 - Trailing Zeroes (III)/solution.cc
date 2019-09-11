#include <bits/stdc++.h>
using namespace std;

long long zeros( long long x) {
    long long a = 0, b = 0;
    long long temp = 5;
    while( temp <= x ) {
        a += x/temp;
        temp *= 5;
    }
    return a;
}

long long bs( int q ) {
    long long l = 0, r = (long long)1e9;
    while( r-l != 1 ) {
        long long mid = (l+r)>>1;
        if( q <= zeros(mid) ) {
            r = mid;
        } else { 
            l = mid;
        }
    }
    return r;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, q;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> q;
        long long ans = bs(q);
        cout << "Case " << cases << ": ";
        if( zeros(ans) == q ) {
            cout << ans << '\n';
        } else {
            cout << "impossible\n";
        }
    }
    return 0;
}