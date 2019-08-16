#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
const int tam = 10005;
ii range[tam];
ii v[tam];
int k, N, S, D; 

int dist( int a ) {
    return sqrt( 1LL*D*D - 1LL*a*a );
}

bool check( int  x ) {
    for( int i = 0; i < N; i++ ) {
        if( D < v[i].second - x ) return false;
        int delta = dist( v[i].second - x );
        range[i].first = v[i].first + delta;
        range[i].second = v[i].first - delta;
    }
    sort( range, range+N );
    int cant = 0;
    for( int i = 0; i < N; ) {
        int cur = range[i].first;
        while( i < N && range[i].second <= cur ) i++;
        cant++;
    }
    return cant <= S;
}

void solve() {
    cin >> k >> N >> S >> D;
    for(int i = 0; i < N; i++ ) {
        cin >> v[i].first >> v[i].second;
    }
    int l = k-D, r = k+1;
    while( r - l != 1 ) {
        int mid = (l+r)>>1;
        if( check(mid) ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if( r == k+1 ) {
        cout << "impossible\n";
    } else {
        cout << k-r << '\n';
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}