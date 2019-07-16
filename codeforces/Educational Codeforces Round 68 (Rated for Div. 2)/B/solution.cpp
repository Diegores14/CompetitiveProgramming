#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, n, m;
    cin >> q;
    while(q--) {
        cin >> n >> m;
        vector< string > v(n);
        for(string &i: v) {
            cin >> i;
        }
        set<int> se;
        int ans1 = 5e6, ans2 = 5e6;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = 0; j < m; j++) {
                temp += (v[i][j] != '*');
            }
            if(temp == ans1) {
                se.insert(i);
            }
            if(temp < ans1) {
                ans1 = temp;
                se.clear();
                se.insert(i);
            }
        }
        for(int j = 0; j < m; j++) {
            int temp = 0;
            bool flag = true;
            for(int i = 0; i < n; i++) {
                if(flag && v[i][j] != '*' && se.count(i)) {
                    flag = false;
                    continue;
                }
                temp += (v[i][j] != '*');
            }
            ans2 = min(ans2, temp);
        }
        cout << ans1 + ans2 << '\n';
    }
    return 0;
}