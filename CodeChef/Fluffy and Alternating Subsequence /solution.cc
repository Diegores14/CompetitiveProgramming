#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int tam = 300010;
typedef pair< int, long long > iL;
iL st[2][4*tam];

void update( int node, int b, int e, int pos, int seg, iL value ) {
    if( pos < b || e < pos ) return;
    if( b == e ) {
        st[seg][node] = value;
    } else {
        int mid = (b + e)>>1, left = (node<<1), right = left + 1;
        update( left, b, mid, pos, seg, value );
        update( right, mid+1, e, pos, seg, value );
        if( st[seg][left].first == st[seg][right].first )
            st[seg][node] = iL(st[seg][left].first, (st[seg][left].second + st[seg][right].second)%mod );
        else 
            st[seg][node] = max(st[seg][left], st[seg][right] );
    }
}

iL query( int node, int b, int e, int l, int r, int seg ) {
    if( r < b || e < l ) return iL(0, 0);
    if( l <= b && e <= r ) {
        return st[seg][node];
    } else {
        int mid = (b + e)>>1, left = (node<<1), right = left + 1;
        iL a = query( left, b, mid, l, r, seg );
        iL b = query( right, mid+1, e, l, r, seg );
        if( a.first == b.first )
            return iL( a.first, (a.second + b.second)%mod );
        else 
            return max( a, b );
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for( int &i: a ) {
        cin >> i;
    }
    for( int i = n-1; i >= 0; i-- ) {
        iL temp = query(1, 0, n+3, 0, a[i]-1, 0 );
        iL temp2 = query(1, 0, n+3, a[i]+1, n+3, 1 );
        if( temp.first == 0 ) temp.second = 1;
        if( temp2.first == 0 ) temp2.second = 1;
        temp.first++;
        temp2.first++;
        update( 1, 0, n+3, a[i], 1, temp);
        update( 1, 0, n+3, a[i], 0, temp2);
    }
    iL temp = query(1, 0, n+3, 0, n+3, 0);
    iL temp2 = query(1, 0, n+3, 0, n+3, 1);
    if( temp.first == temp2.first ) temp.second = (temp.second + temp2.second)%mod;
    else temp = max( temp, temp2 );
    cout << temp.first << ' ' << temp.second << '\n';
    return 0;
}