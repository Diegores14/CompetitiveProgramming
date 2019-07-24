#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long sum = 0, temp, q, n, k;
    cin >> q;
    while(q--) {
        sum = 0;
        cin >> n >> k;
        int v[n];
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += (v[i]&1);
        }
        if( sum >= k  && ((sum-k+1)&1) ) {
            cout << "YES\n";
            k--;
            for(int i = 0; k && i < n; i++) {
                if( (v[i]&1) ) {
                    cout << i+1 << ' ';
                    k--;
                }
            }
            cout << n << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}