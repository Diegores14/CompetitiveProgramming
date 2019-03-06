#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    int n; 
    cin >> n;
    vector<long long> v(2*n);
    for(long long &i: v) {
        cin >> i;
    }
    sort( v.begin(), v.end() );
    long long ans = (v[n-1] - v[0]) * ( v[n*2 - 1] - v[n]);
    for(int i=1; i<n; i++) {
        ans = min(ans, (v[n*2 - 1] - v[0]) * (v[i+n-1] - v[i]));
    }
    cout << ans << '\n';
    return 0;
}