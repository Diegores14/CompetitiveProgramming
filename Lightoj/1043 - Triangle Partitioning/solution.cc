#include <bits/stdc++.h>
using namespace std;

long double heron(long double a, long double b, long double c) {
    long double p = (a+b+c)/2;
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    long double a, b, c, r;
    int t;
    cin >> t;
    cout << fixed << setprecision(6);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b >> c >> r;
        long double A = ( heron( a, b, c ) * r ) / ( r+1 );
        long double k = ( 2 * sqrt(A) )/( sqrt( sqrt( (a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c) ) ) );
        cout << "Case " << cases << ": " << k*a << '\n';
    }
    return 0;
}