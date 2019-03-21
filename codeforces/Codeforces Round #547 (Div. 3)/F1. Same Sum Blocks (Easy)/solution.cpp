#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int v[n];
    for(int &i: v) {
        cin >> i;
    }
    map<int, vector< pair<int, int> > > m;
    for(int r=0; r<n; r++) {
        int temp = 0;
        for(int l=r; l >= 0; l--) {
            temp += v[l];
            m[temp].emplace_back(make_pair(l, r));
        }
    }
    vector< pair<int, int> > ans;
    for(auto &i: m) {
        vector< pair<int, int> > temp;
        int r = -1;
        for(auto &j: i.second) {
            if(r < j.first) {
                r = j.second;
                temp.emplace_back(j);
            }
        }
        if(ans.size() < temp.size()) {
            ans = temp;
        }
    }
    cout << ans.size() << '\n';
    for(auto &i: ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    return 0;
}