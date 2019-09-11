#include <bits/stdc++.h>
using namespace std;
double L, n, c, lp;
const double PI = acos(-1);

bool check( double theta ) {
    double r = (L/2)/sin(theta/2);
    return r*theta >= lp;
}

double solve() {
    double l = 0, r = PI;
    int it = 100;
    while( it-- ) {
        double mid = (l+r)/2;
        if( check(mid) ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    double R = (L/2)/sin(r/2);
    return R - (L/2)/tan(r/2);
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> L >> n >> c;
        lp = (1+n*c)*L;
        cout << "Case " << cases << ": " << solve() << '\n';
    }
    return 0;
}