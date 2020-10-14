#include <bits/stdc++.h>
using namespace std;
const int tam = 2e5+7;
long long st[4*tam];
long long lazy[4*tam];
long long v[tam];
 
void build( int p, int b, int e ) {
    if( b == e ) {
        st[p] = v[b];
    } else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        build( left, b, mid );
        build( right, mid+1, e );
    }
}
 
void push_down( int p, int b, int e ) {
    st[p] += lazy[p];
    if( b != e ) {
        int left = p<<1;
        lazy[left] += lazy[p];
        lazy[left+1] += lazy[p];
    }
    lazy[p] = 0;
}
 
void update( int p, int b, int e, int l, int r, int value ) {
    if( lazy[p] ) push_down(p, b, e);
    if( r < b || e < l ) return;
    if( l <= b && e <= r ) {
        lazy[p] = value;
        push_down(p, b, e);
    } else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        update( left, b, mid, l, r, value );
        update( right, mid+1, e, l, r, value );
    }
}
 
long long query( int p, int b, int e, int pos ) {
    if( lazy[p] ) push_down(p, b, e);
    if( b==e ) return st[p];
    else {
        int mid = (b+e)/2, left = p<<1, right = left+1;
        if( pos <= mid)
            return query(left, b, mid, pos);
        else 
            return query(right, mid+1, e, pos);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q, tp, l, r, value;
    cin >> n >> q;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    build( 1, 0, n-1 );
    while( q-- ) {
        cin >> tp >> l;
        if( tp == 1 ) {
            cin >> r >> value;
            update( 1, 0, n-1, l-1, r-1, value );
        } else {
            cout << query(1, 0, n-1, l-1) << '\n';
        }
    }
    return 0;
}