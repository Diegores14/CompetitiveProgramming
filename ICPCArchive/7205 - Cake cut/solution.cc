#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+5;
long long total = 0;
long long x[tam], y[tam], area[tam];

long long cal( int l, int r ) {
    return abs(area[r] - area[l] + x[r]*y[l] - x[l]*y[r]);
}

long long ternarySearch( int l, int r ) {
    int pos = l;
    while( r - l > 2 ) {
        int a = l + (r-l)/3;
        int b = r - (r-l)/3;
        long long A1 = cal( pos, a);
        long long A2 = cal( pos, b);
        if( min(A1, total-A1) < min(A2, total-A2) ) {
            l = a;
        } else {
            r = b;
        }
    }
    long long A1 = cal( pos, l );
    long long A2 = cal( pos, r );
    long long A3 = cal( pos, l+1 );
    A1 = min( A1, total-A1 );
    A2 = min( A2, total-A2 );
    A3 = min( A3, total-A3 );
    return max( A1, max( A2, A3 ) );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while( cin >> n ) {
        cin >> x[0] >> y[0];
        area[0] = 0;
        total = 0;
        for( int i = 1; i < n; i++ ) {
            cin >> x[i] >> y[i];
            total += x[i-1]*y[i] - x[i]*y[i-1];
            area[i] = total;
        }
        total += x[n-1]*y[0] - x[0]*y[n-1];
        x[n] = x[0];
        y[n] = y[0];
        area[n] = total;
        for( int i = 1; i < n; i++ ) {
            x[n+i] = x[i];
            y[n+i] = y[i];
            area[n+i] = x[n+i-1]*y[n+i] - x[n+i]*y[n+i-1] + area[n+i-1];
        }
        total = abs( total );
        long long ans = 1e18;
        //cout << cal()
        for( int i = 0; i < n; i++) {
            //cout << ternarySearch(i, n-1) << '\n';
            ans = min( ans, ternarySearch(i, i+n-1) );
        }
        cout << total-ans << ' ' << ans << '\n';
    }
    return 0;
}