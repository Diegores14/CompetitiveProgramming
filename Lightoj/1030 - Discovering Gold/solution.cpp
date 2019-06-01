#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, count;
    int v[105];
    long double pro[105];
    cout << fixed << setprecision(8);
    cin >> t;
    for( int cases = 1; cases <= t; cases++) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];
        long double ans = 0;
        memset(pro, 0, sizeof pro);
        pro[0] = 1;
        for(int i = 0; i < n; i++) {
            int cant = min(6, n-i-1);
            for(int j = 1; j <= cant; j++) {
                pro[i+j] += pro[i]/cant;
            }
            ans += v[i] * pro[i];
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}