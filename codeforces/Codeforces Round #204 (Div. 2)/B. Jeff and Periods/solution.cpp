#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    map< int, vector<int> > m;
    vector< pair<int,int> > ans;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        m[temp].emplace_back(i);
    }
    for(auto &i: m) {
        if(i.second.size() == 1) {
            ans.emplace_back(make_pair(i.first, 0));
        } else {
            bool flag = true;
            int temp = i.second[1] - i.second[0];
            for(int j=1; j<i.second.size(); j++) {
                if(temp != i.second[j] - i.second[j-1]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.emplace_back(make_pair(i.first, temp));
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto &i: ans) {
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}