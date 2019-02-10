#include <bits/stdc++.h>
using namespace std;
int n, x, y;

bool isView(vector<int> &xs, vector<int> &ys, int pos) {
    long double m = (long double)(y-pos)/x;
    for(int i=0; i<n && xs[i] < x; i++) {
        if(m * (xs[i]-x) + y < ys[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    n <<= 1;
    vector<int> xs(n+1), ys(n+1, 0);
    cin >> xs[0];
    xs[n] = 10000000;
    for(int i=1; i<n; i++) {
        cin >> xs[i];
        ys[i] = ys[i-1] + ((i&1)? 1 : -1) * (xs[i] - xs[i-1]);
    }
    cin >> x;
    int l = -1, r = n;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        if(xs[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if(ys[l] < ys[r]) {
        y = ys[l] + x - xs[l];
    } else {
        y = ys[l] - (x - xs[l]); 
    }
    l = -1; r = 2000001;
    while(r-l != 1) {
        int mid = (l+r)>>1;
        if(isView(xs, ys, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    return 0;
}
