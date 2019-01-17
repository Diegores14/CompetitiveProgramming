#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(m);
    for(auto &i: v) {
        cin >> i.second >> i.first;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int i=m-1;
    for(; i>=0; i--) {
        ans += v[i].first * v[i].second;
        n -= v[i].second;
        if(n <= 0) {
            break;
        }
    }
    if(n < 0) {
        ans += n * v[i].first;
    }
    cout << ans << '\n';
    return 0;
}