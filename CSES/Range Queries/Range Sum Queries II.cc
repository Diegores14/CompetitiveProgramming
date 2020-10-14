#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+7;
long long st[4*tam];
long long v[tam];
 
void build( int p, int b, int e ) {
    if( b == e ) {
        st[p] = v[b];
    } else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        build( left, b, mid );
        build( right, mid+1, e );
        st[p] = st[left]+st[right];
    }
}
 
void update( int p, int b, int e, int pos, int value ) {
    if( pos < b || e < pos ) return;
    if( b == e ) {
        st[p] = value;
    } else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        update( left, b, mid, pos, value );
        update( right, mid+1, e, pos, value );
        st[p] = st[left]+st[right];
    }
}
 
long long query( int p, int b, int e, int l, int r ) {
    if( r < b || e < l ) return 0;
    if( l <= b && e <= r ) return st[p];
    else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        return query(left, b, mid, l, r) + query(right, mid+1, e, l, r);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, tp, l, r;
    cin >> n >> q;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    build( 1, 0, n-1 );
    while( q-- ) {
        cin >> tp >> l >> r;
        if( tp == 1 ) {
            update( 1, 0, n-1, l-1, r );
        } else {
            l--; r--;
            cout << query(1, 0, n-1, l, r) << '\n';
        }
    }
    return 0;
}