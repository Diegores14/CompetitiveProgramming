#include <bits/stdc++.h>
using namespace std;
double ration;

bool check( double W ) {
    double L = ration*W;
    double R = sqrt( W*W + L*L )/2;
    double arc = 2*R*acos((2*R*R-W*W)/(2*R*R));
    return 400 <= arc + 2*L;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    char c;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        double a, b, l = 0, r = 400;
        cin >> a >> c >> b;
        ration = double(a)/b;
        int it = 60;
        while( it-- ) {
            double mid = (r+l)/2;
            if( check( mid ) ) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << "Case " << cases << ": " << ration*r << ' ' << r << '\n';
    }
    return 0;
}