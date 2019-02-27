#include <bits/stdc++.h>
using namespace std;

bool validation(long long x1, long long y1, long long x2, long long y2, long long r) {
    return r*r >= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if(xa > xb) {
        swap(xa, xb);
    }
    if(ya > yb) {
        swap(ya, yb);
    }
    int n; 
    cin >> n;
    long long x[n], y[n], r[n];
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    long long ans = 0;
    for(int i=xa; i<=xb; i++) {
        int temp = 1;
        for(int j=0; j<n; j++) {
            if(validation(i, ya, x[j], y[j], r[j])) {
                temp = 0; break;
            }
        }
        ans += temp;
        temp = 1;
        for(int j=0; j<n; j++) {
            if(validation(i, yb, x[j], y[j], r[j])) {
                temp = 0; break;
            }
        }
        ans += temp;
    }
    for(int i=ya+1; i<yb; i++) {
        int temp = 1;
        for(int j=0; j<n; j++) {
            if(validation(xb, i, x[j], y[j], r[j])){
                temp = 0; break;
            }
        }
        ans += temp;
        temp = 1;
        for(int j=0; j<n; j++) {
            if(validation(xa, i, x[j], y[j], r[j])){
                temp = 0; break;
            }
        }
        ans += temp;
    }
    cout << ans << '\n';
    return 0;
}