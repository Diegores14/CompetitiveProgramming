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
    int ans = 1e9;
    for(int mid = 0; mid<10000; mid++) {
        set<int> se;
        for(int i: v) {
            if(abs(mid -i) != 0)
                se.insert(abs(mid-i));
        }
        if(se.size() == 1) {
            ans = min(ans, *se.begin());
        }
        if(se.size() == 0) {
            ans = 0;
        }
        se.clear();
    }
    if(ans != 1e9)
        cout << ans << '\n';
    else 
        cout << -1 << '\n';
    return 0;
}