#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    long long v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    long long ans = 1e18;
    for( int i = 1; i < n-1; i++ ) {
        long long mmax = 0;
        for( int j = 1; j < n; j++ ) {
            if( i != j) 
                mmax = max(v[j] - v[j-1], mmax);
            else {
                mmax = max(v[j+1] - v[j-1], mmax);
            }
        }
        ans = min( mmax, ans );
    }
    cout << ans << '\n';
    return 0;
}