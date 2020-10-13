#include <iostream>
using namespace std;
const int k = 18;
const int tam = 3e5;
int st[tam][k];
int v[tam];
int loga[tam];
int n, q;

void build() {
    loga[1] = 0;
    for( int i = 2; i <= n; i++ ) 
        loga[i] = loga[i/2]+1;
    for( int i = 0; i < n; i++ ) 
        st[i][0] = v[i];
    for( int j = 1; j < k; j++ )
        for( int i = 0; i < n; i++ ) {
            st[i][j] = st[i][j-1];
            if( i+(1<<(j-1)) < n )
                st[i][j] = min( st[i][j], st[i+(1<<(j-1))][j-1] );
        }
}

int query( int l, int r ) {
    int d = loga[r-l+1];
    return min( st[l][d], st[r-(1<<d)+1][d] );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for( int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    build();
    int l, r;
    while( q-- ) {
        cin >> l >> r; l--; r--;
        cout << query(l, r) << '\n';
    }
    return 0;
}