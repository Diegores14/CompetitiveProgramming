#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, t, d;
    cin >> n >> m;
    vector<long long> a(n), c(n);
    long long totalDishes = 0;
    vector< pair<int, int> > order(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
        totalDishes += a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> c[i];
        order[i] = make_pair(c[i], i);
    }
    sort( order.begin(), order.end() );
    int l = 0;
    for( int i = 0; i<m; i++) {
        cin >> t >> d;
        totalDishes -= d;
        if(0 <= totalDishes) {
            long long ans = 0;
            int temp = min(d, a[t-1]);
            ans += temp*c[t-1];
            a[t-1] -= temp;
            d -= temp;
            while(d) {
                temp = min(d, a[order[l].second]);
                ans += temp * c[order[l].second];
                d -= temp;
                a[order[l].second] -= temp;
                if(a[order[l].second] == 0) {
                    l++;
                }
            }
            cout << ans << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}