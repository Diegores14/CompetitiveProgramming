#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, a, b, r1=0, temp, p2 = 1000000000;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        r1 = max(r1, temp);
    }
    cin >> m;
    vector<int> v(m);
    for(int &i: v) {
        cin >> i;
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> temp;
        p2 = min(p2, temp);
    }
    cin >> a >> b;
    long double ans = 0;
    for(int &i: v) {
        ans = max(ans, sqrt( (long double)(1LL*b*i*r1*r1)/(1LL*a*p2 + 1LL*b*i) ));
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}