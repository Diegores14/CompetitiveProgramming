#include <bits/stdc++.h>
using namespace std;
double x, y, c;
double eps = 1e-8;
double PI = acos(-1);
// x' = width*sin(angle2)/sin(PI-angle1-angle2)
// c' = x'sin(angle1)


bool check( double mid ) {
    double angle1 = acos(mid/x);
    double angle2 = acos(mid/y);
    double c_ = ( mid*sin(angle1)*sin(angle2) )/sin(PI-angle1-angle2);
    return c_ >= c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> x >> y >> c;
        double l = 0, r = min(x, y) - eps;
        int it = 100;
        while( it-- ) {
            double mid = (l+r)/2;
            if( check(mid) ) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << "Case " << cases << ": " << l << '\n';
    }
    return 0;
}