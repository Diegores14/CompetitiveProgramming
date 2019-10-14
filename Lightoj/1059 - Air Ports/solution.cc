#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v;
    long long w;
    edge() {}
    edge( int u, int v, long long w ): u(u), v(v), w(w) {}
    bool operator <( edge other ) {
        return w < other.w;
    }
};
vector< edge > E;

struct DisjoinSet {
    int N;
    vector< int > p;
    DisjoinSet(int N): N(N), p(N) {
        for( int i = 0; i < N; i++ ) {
            p[i] = i;
        }
    }
    int findSet( int i ) { return (i == p[i])? i: p[i] = findSet(p[i]); }
    bool isSame( int i, int j ) { return findSet(i) == findSet(j); }
    void unionSet( int i, int j ) {
        int x = findSet( i ), y = findSet( j );
        if( x != y ) {
            p[x] = y;
        }
    }
};

void solve() {
    E.clear();
    long long n, m, a, u, v, cost;
    cin >> n >> m >> a;
    for( int i = 0; i < m; i++ ) {
        cin >> u >> v >> cost; u--; v--;
        E.push_back( edge(u, v, cost) );
    }
    sort( E.begin(), E.end() );
    DisjoinSet d(n);
    long long ans = 0;
    for( edge e: E ) {
        if( !d.isSame( e.u, e.v ) && e.w < a ) {
            d.unionSet( e.u, e.v );
            ans += e.w;
        }
    }
    set< int > s;
    for( int i = 0; i < n; i++ ) {
        s.insert( d.findSet(i) );
    }
    cout << ans + a*s.size() << ' ' << s.size() << '\n';
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