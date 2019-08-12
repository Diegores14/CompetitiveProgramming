#include <bits/stdc++.h>
using namespace std;

long double dist( int x1, int y1, int x2, int y2 ) {
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

long double cosRule( long double a, long double b, long double c ) {
    return acos( ((b*b) + (c*c) - (a*a))/(2*b*c) );
}

long double PI = acos(-1);

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, x1, x2, y1, y2, r1, r2;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if( r2 > r1 ) {
            swap(r1, r2);
            swap(x1, x2);
            swap(y1, y2);
        }
        long double len = dist( x1, y1, x2, y2 );
        if( r1+r2 <= len) cout << 0 << '\n';
        else if( r1+r2 > len && r2 + len > r1) {
            long double thetha = cosRule(r1, r2, len);
            long double alpha = cosRule(r2, r1, len);
            cout << alpha*r1*r1 - 0.5*sin(2*alpha)*r1*r1 + thetha*r2*r2 - 0.5*sin(2*thetha)*r2*r2 << '\n';
        } else {
            cout << PI*r2*r2 << '\n';
        }
    }
    return 0;
}