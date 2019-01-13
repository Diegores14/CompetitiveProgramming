#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, ans = 0;
    int total = 0;
    cin >> n >> k;
    vector<int> v(n);
    for(int &i: v ) {
        cin >> i;
        total += i;
    }
    for(int b=0; b<n; b++) {
        int i = -b/k;
        int temp = total;
        for(; b+i*k<n; i++) {
            temp -= v[b+i*k];
        }
        ans = max(ans, abs(temp));
    }
    cout << ans << '\n';
    return 0;
}