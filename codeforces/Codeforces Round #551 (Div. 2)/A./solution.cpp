#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long min = 1e18, ans = -1;
    int n, t, a, b;
    cin >> n >> t;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        while(a < t) {
            a += b;
        }
        if(min > a) {
            ans = i+1;
            min = a;
        }
    }
    cout << ans << '\n';
    return 0;
}