#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t, k, d;
    cin >> n >> m;
    vector< int > v(n, 0);
    for(int i=0; i<m; i++) {
        cin >> t >> k >> d;
        int cant = 0;
        for(int i=0; i<n; i++) {
            if(v[i] < t) {
                cant++;
            }
        }
        if(cant >= k) {
            int ans = 0;
            for(int i=0; i<n && k; i++) {
                if(v[i] < t) {
                    ans += i+1;
                    v[i] = t+d-1;
                    k--;
                }
            }
            cout << ans << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}