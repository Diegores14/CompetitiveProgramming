#include <bits/stdc++.h>
using namespace std;
int n;
long long v[22];
long long sum = 0;
long long ans = 1e18;
 
void solve( int idx=0, long long curr = 0 ) {
    if(idx == n)  {
        ans = min( ans, abs(2*curr-sum) );
        return;
    }
    solve( idx+1, curr+v[idx]);
    solve( idx+1, curr);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
        sum += v[i];
    }
    solve();
    cout << ans << '\n';
    return 0;
}
