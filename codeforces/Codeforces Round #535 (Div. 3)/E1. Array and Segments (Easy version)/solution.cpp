#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ans = 0, r = 1, cant = 0;
    cin >> n >> m;
    vector<int> v(n), b;
    vector< pair<int,int> > segments(m);
    for(int &i: v) {
        cin >> i;
    }
    for(auto &i: segments) {
        cin >> i.first >> i.second;
    }
    for(int i=1; i<=n; i++) {
        b = v;
        int temp = 0;
        for(int j = 0; j<m; j++) {
            if(i < segments[j].first || segments[j].second < i) {
                temp++;
                for(int k=segments[j].first-1; k < segments[j].second; k++) {
                    b[k]--;
                }
            }
        }
        int mmax = -10000000, mmin = 10000000;
        for(int &j: b) {
            mmax = max(mmax, j);
            mmin = min(mmin, j);
        }
        if(ans < mmax - mmin) {
            ans = mmax - mmin;
            r = i;
            cant = temp;
        }
    }
    cout << ans << '\n' << cant << '\n';
    for(int i=0; i<m; i++) {
        if(r < segments[i].first || segments[i].second < r) {
            cout << i+1 << ' ';
        }
    }
    cout << '\n';
    return 0;
}