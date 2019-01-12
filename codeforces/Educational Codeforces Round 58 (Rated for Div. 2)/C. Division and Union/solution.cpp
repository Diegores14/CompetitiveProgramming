#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector< pair< pair<int,int>, int> >v(n);
        vector<int> ans(n, 2);
        for(int i=0; i<n; i++) {
            cin >> v[i].first.first >> v[i].first.second;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        int R = v[0].first.second;
        int i=0;
        for(; i<n; i++) {
            if(v[i].first.first <= R) {
                ans[v[i].second] = 1;
                R = max(R, v[i].first.second);
            } else {
                break;
            }
        }
        if(i < n) {
            for(int i=0; i<n; i++) {
                cout << ans[i] << ((i==n-1)? '\n': ' ');
            }
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}