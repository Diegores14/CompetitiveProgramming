#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
// first Case 
// X = D, X <= W/PI
// v(X) = 1/4 * PI * X * X * ( H - X )
// v'(X) = 1/4 * PI * (2H - 3X ) * X
// V'(X) = 0   =>   X = (2H)/3
// second Case
// ( X - D )^2 + ( W - D )^2 >= D^2
// X^2 - 2*X*D + D^2 + W^2 - 2*W*D + D^2 >= D^2
// D^2 - 2*D*( X + W ) + ( X^2 + W^2 ) >= 0
// D * PI <= H - X   =>   X <= H - D*PI
// X = H - D*PI;
// D^2 - 2*D*( H - D*PI + W ) + (H - D*PI)^2 + W^2 >= 0
// D^2 - 2*D*( H + W ) + 2*(D^2)*PI + H^2 - 2*D*PI*H + D^2*PI^2 + W^2 >= 0
// (D^2)*( 1 + 2*PI + PI^2 ) -2*( H + W + PI*H )*D + (H^2 + W^2) >= 0;
// D =( ( H + W + PI*H ) - sqrt( ( H + W + PI*H )^2 - ( 1 + 2*PI + PI^2 )*(H^2 + W^2) ) ) /( 1 + 2*PI + PI^2 )
// D =( ( H + W + PI*H ) - sqrt( ( H + W + PI*H )^2 - ( 1 + 2*PI + PI^2 )*(H^2 + W^2) ) ) /( 1 + 2*PI + PI^2 )


// D = X and X = H - X*PI; => X*(1+PI) = H; => X = H/(1+PI);

long double formula( long double a, long double b, long double c ) {
    return (b-sqrt( b*b - a*c ))/a;
}

long double solve( long double w, long double h ) {
    long double X = min( w/PI, (2*h)/3);
    long double v = PI * X * X * ( h - X ) / 4;
    long double D = min( w, min(h/(1+PI), formula( 1+2*PI+PI*PI , h+w+PI*h, h*h+w*w )) );
    v = max( v, PI * D * D * w / 4);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while( t-- ) {
        int w, h;
        cin >> w >> h;
        cout << max( solve( w, h ), solve( h, w )) << '\n';
    }
    return 0;
}