#include <bits/stdc++.h>
using namespace std;
long double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        long long r1, r2, h, p;
        cin >> r1 >> r2 >> h >> p;
        long double m = (long double)( r1 - r2 )/h;
        long double b = r2;
        cout << "Case " << cases << ": " << (( PI*( m*p + b )*( m*p + b )*( m*p + b ) ) - (PI*b*b*b) )/(3*m) << '\n';
    }
    return 0;
}