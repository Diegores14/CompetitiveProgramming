#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
    edge() {}
    edge( int u, int v, int w ): u(u), v(v), w(w) {}
    bool operator <( edge other ) {
        return w < other.w;
    }
};
vector < edge > E;

struct DisjointSet {
    vector< int > p, cant;
    int N;
    DisjointSet( int N ): N(N), p(N), cant(N) {
        for( int i = 0; i < N; i++ ) {
            p[i] = i;
            cant[i] = 1;
        }
    }
    int findSet( int i ) { return i == p[i]? i: p[i] = findSet(p[i]); }
    bool isSame( int i, int j ) { return findSet(i) == findSet(j); }
    void unionSet( int i, int j ) {
        int x = findSet(i), y = findSet(j);
        if( x != y ) {
            p[x] = y;
            cant[y] += cant[x];
        }
    }
};

void solve() {
    E.clear();
    int n, temp;
    cin >> n;
    DisjointSet d1(n), d2(n);
    long long sum = 0;
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            cin >> temp;
            if( temp > 0 ) {
                sum += temp;
                E.push_back( edge( i, j, temp) );
                d1.unionSet( i, j );
            }
        }
    }
    if( d1.cant[d1.findSet(0)] == n ) {
        sort( E.begin(), E.end() );
        long long ans = 0;
        for( edge e: E ) {
            if( !d2.isSame( e.u, e.v ) ) {
                ans += e.w;
                d2.unionSet( e.u, e.v );
            }
        }
        cout << sum - ans << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}