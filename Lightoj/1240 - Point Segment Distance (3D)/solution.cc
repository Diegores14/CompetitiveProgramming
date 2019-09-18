#include <bits/stdc++.h>
using namespace std;
int ax, ay, az, bx, by, bz, px, py, pz, mx, my, mz;

double f( double t ) {
    double x = ax + mx*t;
    double y = ay + my*t;
    double z = az + mz*t;
    x = x - px;
    y = y - py;
    z = z - pz;
    return sqrt( x*x + y*y + z*z );
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
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> ax >> ay >> az >> bx >> by >> bz >> px >> py >> pz;
        mx = bx - ax;
        my = by - ay;
        mz = bz - az;
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}