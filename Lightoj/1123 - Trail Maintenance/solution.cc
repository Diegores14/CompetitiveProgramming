#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    edge(): w(1000000000) {}
    edge( int u, int v, int w ): u(u), v(v), w(w) {}
    bool operator <=( edge other ) const {
        return w <= other.w;
    }
};

struct DistjointSet {
    int N;
    vector< int > p;
    DistjointSet( int N ): N(N), p(N) {
        for( int i = 0; i < N; i++ ) {
            p[i] = i;
        }
    }
    int findSet( int i ) { return (i == p[i])? i : p[i] = findSet(p[i]); }
    bool isSame( int i, int j ) { return findSet(i) == findSet(j); }
    void unionSet( int i, int j ) {
        int x = findSet(i), y = findSet(j);
        if( x != y ) {
            p[x] = y;
        }
    }
};

void solve() {
    int n, w, u, v, cost;
    scanf("%d %d", &n, &w); 
    vector< edge > E(w);
    for( int i = 0; i < w; i++ ) {
        scanf("%d %d %d", &u, &v, &cost); u--; v--;
        edge e = edge(u, v, cost);
        for( int j = 0; j <= i; j++ ) {
            if( e <= E[j] )
                swap( E[j], e );
        }
        DistjointSet d(n);
        int ans = 0, sum = 0;
        for( int j = 0; j <= i; j++ ) {
            if( !d.isSame(E[j].u, E[j].v) ) {
                ans++;
                d.unionSet(E[j].u, E[j].v);
                sum += E[j].w;
            }
        }
        if( ans == n-1 ) {
            printf("%d\n", sum );
        } else {
            printf("-1\n");
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for( int cases = 1; cases <= t; cases++ ) {
        printf("Case %d:\n", cases);
        solve();
    }
    return 0;
}