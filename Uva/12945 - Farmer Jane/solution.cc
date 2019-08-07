#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    long long xi, yi, wi;
    cout << fixed << setprecision(3);
    while( cin >> n ) {
        long long ax = 0, bx = 0, c = 0;
        long long ay = 0, by = 0;
        for(int i = 0; i < n;  i++) {
            cin >> xi >> yi >> wi;
            ax += wi*xi*xi;
            ay += wi*yi*yi;
            bx += wi*xi;
            by += wi*yi;
            c += wi;
        }
        long double x = (long double)bx/c;
        long double y = (long double)by/c;
        cout << ax - 2*bx*x + c*x*x + ay - 2*by*y + c*y*y << '\n';
    }
    return 0;
}