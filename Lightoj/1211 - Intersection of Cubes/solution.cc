#include <bits/stdc++.h>
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, x, y, z, xmax, ymax, zmax, xmin, ymin, zmin;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        xmax = 0; ymax = 0; zmax = 0; xmin = 2000; ymin = 2000; zmin = 2000;
        cin >> n;
        for( int i = 0; i < n; i++ ) {
            cin >> x >> y >> z;
            xmax = max(xmax, x);
            ymax = max(ymax, y);
            zmax = max(zmax, z);
            cin >> x >> y >> z;
            xmin = min(xmin, x);
            ymin = min(ymin, y);
            zmin = min(zmin, z);
        }
        //cout << xmin << ' ' << ymin << ' ' << zmin << ' ' << xmax << ' ' << ymax << ' ' << zmax << '\n';
        long long a = xmin - xmax;
        long long b = ymin - ymax;
        long long c = zmin - zmax;
        cout  << "Case " << cases << ": ";
        if( a >= 0 && b >= 0 && c >= 0 )
            cout << a*b*c << '\n';
        else 
            cout << 0 << '\n';
    }
    return 0;
}