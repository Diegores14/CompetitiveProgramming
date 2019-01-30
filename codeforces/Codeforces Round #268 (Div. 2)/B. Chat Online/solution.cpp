#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector< pair<int, int> > v1(p), v2(q);
    for(auto &i: v1) {
        cin >> i.first >> i.second;
    }
    for(auto &i: v2) {
        cin >> i.first >> i.second;
    }
    int ans = 0;
    for(; l<=r; l++) {
        bool temp = false;
        for(auto &i: v2) {
            for(auto &j: v1)
                if( !(i.second + l < j.first || j.second < i.first + l) ) {
                        temp = true;
                        break;
                }
            if(temp)
                break;
        }
        ans +=  temp;
    }
    cout << ans << '\n';
    return 0;
}