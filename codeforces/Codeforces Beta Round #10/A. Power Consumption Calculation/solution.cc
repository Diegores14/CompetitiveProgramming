#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    pair< int, int > v[n];
    for( int i = 0; i < n; i++ ) {
        cin >> v[i].first >> v[i].second;
    }
    int t = v[0].first;
    long long ans = 0;
    for( int i = 0; i < n-1; i++ ) {
        ans += (v[i].second - v[i].first)*p1;
        t = v[i].second;
        ans += min( v[i+1].first - t, t1 )*p1;
        t = min( v[i+1].first, t + t1 ); 
        ans += min( v[i+1].first - t, t2 )*p2;
        t = min( v[i+1].first, t + t2 ); 
        ans += ( v[i+1].first - t )*p3;
        t = v[i+1].first;
    }
    cout << ans + (v[n-1].second-v[n-1].first)*p1 << '\n';
    return 0;
}