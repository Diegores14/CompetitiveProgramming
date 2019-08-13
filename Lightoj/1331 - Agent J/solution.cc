#include <bits/stdc++.h>
using namespace std;

long double heron( long double a, long double b, long double c ) {
    long double s = ( a + b + c )/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

long double ruleCos( long double a, long double b, long double c ) {
    return acos( (b*b + c*c - a*a)/(2*b*c) );
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        long double r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        long double A = heron( r1+r2, r3+r2, r1+r3);
        A -= (ruleCos( r1+r2, r3+r2, r1+r3)*r3*r3)/2;
        A -= (ruleCos( r3+r2, r1+r2, r1+r3)*r1*r1)/2;
        A -= (ruleCos( r1+r3, r3+r2, r1+r2)*r2*r2)/2;
        cout << "Case " << cases << ": " << A << '\n';
    }
    return 0;
}