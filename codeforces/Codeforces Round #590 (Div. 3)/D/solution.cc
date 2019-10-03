#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+5;
int st[26][4*tam];

void build( int p, int b, int e, string &s ) {
    if( b == e ) {
        st[s[b]-'a'][p] = 1;
    } else {
        int mid = (b+e)/2, left = (p<<1), right = left+1;
        build( left, b, mid, s );
        build( right, mid+1, e, s );
        for( int i = 0; i < 26; i++ ) {
            st[i][p] = st[i][left] + st[i][right];
        }
    }
}

void update( int p, int b, int e, int pos, int value, int letter ) {
    if( pos  < b || e < pos ) return;
    if( b == e ) {
        st[letter][p] = value;
    } else {
        int mid = (b+e)/2, left = (p<<1), right = left+1;
        update( left, b, mid, pos, value, letter );
        update( right, mid+1, e, pos, value, letter );
        st[letter][p] = st[letter][left] + st[letter][right];
    }
}

int query( int p, int b, int e, int l, int r, int letter ) {
    if( r  < b || e < l ) return 0;
    if( l <= b && e <= r ) {
        return st[letter][p];
    } else {
        int mid = (b+e)/2, left = (p<<1), right = left+1;
        return query( left, b, mid, l, r, letter ) + query( right, mid+1, e, l, r, letter );
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    memset( st, 0, sizeof st );
    int q, typ, l, r, pos;
    char c;
    cin >> s >> q;
    build( 1, 0, s.size()-1, s );
    while( q-- ) {
        cin >> typ;
        if( typ == 1 )  {
            cin >> pos >> c; pos--;
            update( 1, 0, s.size()-1, pos, 0, s[pos]-'a' );
            s[pos] = c;
            update( 1, 0, s.size()-1, pos, 1, c-'a' );
        } else {
            cin >> l >> r; l--; r--;
            int ans = 0;
            for( int i = 0; i < 26; i++ ) {
                ans += (query( 1, 0, s.size()-1, l, r, i ) != 0) ;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}