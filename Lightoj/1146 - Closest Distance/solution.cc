#include <bits/stdc++.h>
using namespace std;
int ax, ay, bx, by, cx, cy, dx, dy, mx1, my1, mx2, my2;

double f( double t ) {
    double x1 = ax + mx1*t;
    double y1 = ay + my1*t;
    double x2 = cx + mx2*t;
    double y2 = cy + my2*t;
    double x = x2-x1;
    double y = y2-y1;
    return sqrt( x*x + y*y );
}

double solve() {
    double l = 0, r = 1;
    for( int i = 0; i < 100; i++ ) {
        double left = l + (r-l)/3;
        double right = r - (r-l)/3;
        if( f(left) < f(right) ) {
            r = right;
        } else {
            l = left;
        }
    }
    return f( (l+r)/2 );
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        mx1 = bx-ax; my1 = by-ay; mx2 = dx-cx; my2 = dy-cy;
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}