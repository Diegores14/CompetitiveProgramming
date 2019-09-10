#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int n, q, a, b;
int v[tam];

int solve() {
    int x = -1, r = n, y = -1;
    while( r-x != 1) {
        int mid = (r+x)/2;
        if( v[mid] < a ) {
            x = mid;
        } else {
            r = mid;
        }
    }
    r = n;
    while( r-y != 1) {
        int mid = (r+y)/2;
        if( v[mid] <= b ) {
            y = mid;
        } else {
            r = mid;
        }
    }
    return y - x;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n >> q;
        printf("Case %d:\n", cases);
        for( int i = 0; i < n; i++ ) {
            scanf("%d", &v[i]);
        }
        sort( v, v+n );
        while( q-- ) {
            scanf("%d %d", &a, &b);
            printf("%d\n", solve() );
        }
    }
    return 0;
}