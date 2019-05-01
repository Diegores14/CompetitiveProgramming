#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case " << k <<  ": ";
        cin >> n;
        int v[n];
        for(int &i: v) {
            cin >> i;
        }
        sort(v, v+n);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int l = -1, r = j;
                while(r-l != 1) {
                    int mid = (l+r) >> 1;
                    if(v[i] < v[j] + v[mid]) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                ans += j-r;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}