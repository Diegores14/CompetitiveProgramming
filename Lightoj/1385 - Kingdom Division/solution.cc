#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-9;
// FIRST ECUATION
// (y+c)/c = (a+b)/b => y/c + 1 = a/b + 1 => y/c = a/b
// SECOND ECUATION
// (x+y+a)/(y+a) = (x+y+c+a+b)/(a+b) => x/(y+a) + 1 = (x+y+c)/(a+b) + 1 => x/(y+a) = (x+y+c)/(a+b) =>
// x*(a+b) = (x+y+c)*(y+a) => x*(a+b-y-a) = (y+c)*(y+a) => x = (y+c)*(y+a)/(b-y)

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(10);
    int t;
    long double a, b, c;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> a >> b >> c;
        long double y = (a*c)/b;
        cout << "Case " << cases << ": ";
        if( b-y < eps ) {
            cout << -1 << '\n';
        } else {
            long double x = ((y+c)*(y+a))/(b-y);
            cout << x+y << '\n';
        }
    }
    return 0;
}