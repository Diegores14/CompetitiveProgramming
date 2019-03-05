#include <bits/stdc++.h>
using namespace std;
int desc[5005],  desc1[5005][5005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(desc, 0, sizeof desc);
    memset(desc1, 0, sizeof desc1);
    vector< vector<int> > v(5005);
    int n, q;
    long long total = 0;
    cin >> n >> q;
    vector< pair<int, int> > painters(q);
    int l=0;
    for(auto &i: painters) {
        cin >> i.first >> i.second;
        for(int j=i.first; j<=i.second; j++) {
            v[j].emplace_back(l);
            total += (v[j].size() == 1);
        }
        l++;
    }
    for(int i=0; i<=5000; i++) {
        if(v[i].size() == 1) {
            desc[v[i][0]]++;
        }
        if(v[i].size() == 2) {
            desc1[v[i][0]][v[i][1]]++;
        }
    }
    long long ans = 0;
    for(int i=0; i<q; i++) {
        for(int j=i+1; j<q; j++) {
            ans = max(ans, total - desc[i] - desc[j] - desc1[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}