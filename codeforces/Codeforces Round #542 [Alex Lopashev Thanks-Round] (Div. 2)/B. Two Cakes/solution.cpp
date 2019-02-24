#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    vector< vector<int> > v(n);
    for(int i=0; i<(2*n); i++) {
        cin >> temp;
        v[temp-1].emplace_back(i);
    }
    long long ans = 0, pos1=0, pos2 = 0;
    for(int i=0; i<n; i++) {
        ans += abs(pos1-v[i][0]);
        ans += abs(pos2-v[i][1]);
        pos1 = v[i][0];
        pos2 = v[i][1];
    }
    cout << ans << '\n';
    return 0;
}