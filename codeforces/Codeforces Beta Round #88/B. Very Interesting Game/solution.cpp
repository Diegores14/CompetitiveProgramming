#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, mod;
    cin >> a >> b >> mod;
    int x = min(a, mod - 1), y = min(b, mod - 1);
    for(int i=1; i<=x; i++) {
        int temp = (mod - (1LL * i * 1000000000) % mod) % mod;
        if(temp > y) {
            cout << 1 << ' ';
            string ans = to_string(i);
            while(ans.size() < 9) {
                ans = "0" + ans;
            }
            cout << ans << '\n';
            return 0;
        }
    }
    cout << 2 << '\n';
    return 0;
}