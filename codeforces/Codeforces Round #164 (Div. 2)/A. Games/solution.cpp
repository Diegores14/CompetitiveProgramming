#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    long long ans = 0;
    cin >> n;
    vector< pair<int,int> > v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i != j && v[i].first == v[j].second) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}