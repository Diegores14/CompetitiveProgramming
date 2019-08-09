#include <bits/stdc++.h>
using namespace std;
const int tam = 2050;
int n, d;
int st[tam][tam];
int v[tam][tam];


void segment(int node, int b, int e, int pos, int row) {
    if( b == e ) {
        st[pos][node] = v[row][b];
    } else {
        int mid = ( b + e )>>1, left = node<<1, right = left+1;
        segment( left, b, mid, pos, row );
        segment( right, mid+1, e, pos, row );
        st[pos][node] = max( st[pos][left], st[pos][right] );
    }
}

void build(int node, int b, int e) {
    if( b == e ) {
        segment(1, 0, n-1, node, b);
    } else {
        int mid = ( b + e )>>1, left = node<<1, right = left+1;
        build( left, b, mid);
        build( right, mid+1, e);
        for(int i = 0; i <= 4*n; i++) {
            st[node][i] = max( st[left][i], st[right][i] );
        }
    }
}

int segmentQuery(int node, int b, int e, int pos, int l, int r ) {
    if(r < b || e < l) return 0;
    if( l <= b && e <= r ) {
        return st[pos][node];
    } else {
        int mid = ( b + e )>>1, left = node<<1, right = left+1;
        return max( segmentQuery( left, b, mid, pos, l, r ),
        segmentQuery( right, mid+1, e, pos, l, r ) );
    }
}

int query( int node, int b, int e, int l, int r, int x1, int x2 ) {
    if(r < b || e < l) return 0;
    if( l <= b && e <= r ) {
        return segmentQuery(1, 0, n-1, node, x1, x2);
    } else {
        int mid = ( b + e )>>1, left = node<<1, right = left+1;
        return max( query( left, b, mid, l, r, x1, x2),
        query( right, mid+1, e, l, r, x1, x2) );
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, x, y, s;
    scanf("%d", &t); 
    for( int cases = 1; cases <= t; cases++ ) {
        scanf( "%d %d", &n, &d);
        memset(st, 0, sizeof st);
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                scanf("%d", &v[i][j]); 
            }
        }
        build(1, 0, n-1);
        printf("Case %d:\n", cases );
        while(d--) {
            scanf("%d %d %d", &x, &y, &s); x--; y--; s--;
            printf("%d\n", query(1, 0, n-1, x, x+s, y, y+s) );
        }
    }
    return 0;
}