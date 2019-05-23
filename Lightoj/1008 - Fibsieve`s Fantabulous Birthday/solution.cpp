#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    long long n;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> n;
        long long l = 0, r = 100000000;
        while(r-l != 1) {
            long long mid = (l+r)>>1;
            if(n <= mid*mid) {
                r = mid;
            } else {
                l = mid;
            }
        }
        int x, y;
        if(r*(r-1) < n) {
            x = r*r - n + 1;
            y = r;
        } else {
            x = r;
            y = n - (r-1)*(r-1);
        }
        if((r&1) == 0) swap(x, y);
        cout << "Case " << cases << ": " << x << ' ' << y << '\n';
    }
    return 0;
}