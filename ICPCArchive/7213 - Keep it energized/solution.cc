#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
const int tam = 1e5+5;
int n, m;
int st[4*tam], E[tam];
list< ii > G[tam];


void update( int p, int b, int e, int pos, int val) {
    if( pos < b || e < pos ) return;
    if( b == e ) {
        st[p] = val;
    } else {
        int mid = (b+e)/2, left = p<<1, right = left + 1;
        update( left, b, mid, pos, val );
        update( right, mid+1, e, pos, val );
        int x = st[left];
        int y = st[right];
        if( x == -1 ) x = y;
        if( y == -1 ) y = x;
        st[p] = min( x, y );
    }
}

int query( int p, int b, int e, int l, int r) {
    if( r < b || e < l ) return -1;
    if( l <= b && e <= r ) {
        return st[p];
    } else {
        int mid = (b+e)/2, left = p<<1, right = left + 1;
        int x = query( left, b, mid, l, r );
        int y = query( right, mid+1, e, l, r );
        if( x == -1 ) return y;
        if( y == -1 ) return x;
        return min( x, y );
    }
}

int bs( int x ) {
    int l = 0, r = n+1;
    while( r-l != 1 ) {
        int mid = (l+r)>>1;
        if( E[mid] <= x ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, s, c;
    while( cin >> n >> m ) {
        memset( st, -1, sizeof st);
        for( int i = 0; i < tam; i++ ) {
            G[i].clear();
        }
        E[0] = 0;
        for( int i = 1; i <= n; i++ ) {
            cin >> E[i];
            E[i] += E[i-1];
        }
        for( int i = 0; i < m; i++) {
            cin >> l >> s >> c;
            G[l].push_back( ii(s, c) );
        }
        update( 1, 0, n+1, n+1, 0);
        for( int i = n; i > 0; i-- ) {
            int mmin = 1e9+5;
            for( ii &j: G[i] ) {
                int x = bs( E[i-1]+j.first );
                //cout << i << ' ' << x << '\n';
                int v = query( 1, 0, n+1, i, x );
                if( v != -1 )
                    mmin = min( mmin, j.second + v );
            }
            if( mmin != 1e9+5 ) {
                update( 1, 0, n+1, i, mmin );
            }
        }
        cout << query( 1, 0, n+1, 1, 1 ) << '\n';
    }
    return 0;
}