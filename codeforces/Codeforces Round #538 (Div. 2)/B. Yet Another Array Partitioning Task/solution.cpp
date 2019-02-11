#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, temp;
    long long ans = 0;
    cin >> n >> m >> k;
    vector<int> v(n), order(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        order[i] = v[i];
    }
    sort(order.begin(), order.end());
    map<int, int> se;
    for(int i=n-m*k; i<n ; i++) {
        se[order[i]]++;
        ans += order[i];
    }
    k--;
    cout << ans << '\n';
    temp = 0;
    for(int i=0; i<n && k; i++) {
        if(se[v[i]] > 0) {
            temp++;
            se[v[i]]--;
        }
        if(temp == m) {
            k--;
            temp = 0;
            cout << i+1 << (k? ' ' : '\n');
        }
    }
    return 0;
}