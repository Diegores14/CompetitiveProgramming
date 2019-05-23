#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, m;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n >> m;
        int ans;
        if(min(n, m) == 1) {
            ans = max(n, m);
        } else {
            ans = (n*m +1)/2;
        }
        if(min(n, m) == 2) {
            ans = ((max(n, m))/4)*4;
            ans += ((max(n, m))%4 > 2)? 4 : ((max(n, m))%4)*2;
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}