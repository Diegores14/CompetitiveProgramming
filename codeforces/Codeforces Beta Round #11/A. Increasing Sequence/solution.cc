#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    long long v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    long long ans = 0;
    for( int i = 1; i < n; i++ ) {
        int temp = max( 0LL, (v[i-1]-v[i]+d)/d );
        ans += temp;
        v[i] += temp*d;
    }
    cout << ans << '\n';
    return 0;
}