#include <bits/stdc++.h>
using namespace std;
const int tam = 105;
long long x[tam];
int n;

void gauss() {
    int i = 0, j = 63, r = 0;
    while( i < n && j >= 0 ) {
        r = i;
        for( int k = i; k < n; k++ ) {
            if( (x[k]>>j)&1 ) {
                r = k;
                break;
            }
        }
        if( (x[r]>>j)&1 ) {
            if( r != i ) swap( x[r], x[i] );
            for( int k = 0; k < n; k++ ) {
                if( i != k && ((x[k]>>j)&1) ) {
                    x[k] ^= x[i];
                }
            }
            i++;
        }
        j--;
    }
}

void solve() {
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> x[i];
    }
    gauss();
    long long ans = 0;
    for( int i = 0; i < n;  i++ ) {
        ans ^= x[i];
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