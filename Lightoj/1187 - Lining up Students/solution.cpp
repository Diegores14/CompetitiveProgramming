#include <bits/stdc++.h>
using namespace std;
//const int tam = 1e5+1;
//int v[tam];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, tmp;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> tmp;
            if(i - tmp <= ans && i) {
                ans = ans + 1;
            }
        }
        cout << "Case " << cases << ": " << ans + 1 << '\n';
    }
    return 0;
}