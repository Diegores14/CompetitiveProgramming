#include <bits/stdc++.h>
using namespace std;

long double heron( long double a, long double b, long double c ) {
    long double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

long double cosRule( long double a, long double b, long double c ) {
    return acos((b*b + c*c - a*a)/(2*b*c));
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    long double a, b, c, d;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b >> c >> d;
        if( a < c ) swap(a, c);
        cout << "Case " << cases << ": ";
        long double area = 0;
        long double M = a-c;
        area += heron(b, d, M);
        long double thetha = cosRule(b, d, M);
        long double h = d*sin(thetha);
        area += h*c;
        cout << area << '\n';
    }
    return 0;
}