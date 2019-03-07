#include <bits/stdc++.h>
using namespace std;
long long n, m;
int a[1005], b[1005];

bool val(long double fuel) {
    bool ans = true;
    for(int i=0; i<n; i++) {
        fuel -= (m + fuel)/a[i];
        if(fuel < 0) {
            ans = false;
            break;
        }
        fuel -= (m + fuel)/b[(i+1)%n];
        if(fuel < 0) {
            ans = false;
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }
    long double l = 0, r= 1e10;
    while(1e-10 <= r-l) {
        long double mid = (l+r)/2;
        if( val(mid) ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if(r < 1e10)
        cout << fixed << setprecision(10) << r << '\n';
    else {
        cout << -1 << '\n';
    }
    return 0;
}