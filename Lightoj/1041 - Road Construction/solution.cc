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

struct DisjointSet {
    int N;
    vector< int > p, cnt;
    DisjointSet( int N ): N(N), p(N), cnt(N) {
        for( int i = 0; i < N; i++ ) {
            p[i] = i;
            cnt[i] = 1;
        }
    }
    int findSet( int i ) { return ( i == p[i]? i: p[i] = findSet(p[i]) ); }
    bool isSame( int i, int j ) { return findSet(i) == findSet(j); }
    void unionFind( int i, int j ) {
        int x = findSet( i ), y = findSet( j );
        if( x != y ) {
            p[x] = y;
            cnt[y] += cnt[x];
        }
    }
};

void solve() {
    int n, cost;
    map< string, int > m;
    string s1, s2;
    cin >> n;
    vector< edge > E;
    for( int i = 0; i < n; i++ ) {
        cin >> s1 >> s2 >> cost;
        if( m.count(s1) == 0 ) {
            m[s1] = m.size();
        }
        if( m.count(s2) == 0 ) {
            m[s2] = m.size();
        }
        E.push_back( edge(m[s1], m[s2], cost) );
    }
    sort( E.begin(), E.end() );
    DisjointSet d1( m.size() );
    long long ans = 0;
    for( edge e : E ) {
        if( !d1.isSame( e.u, e.v ) ) {
            d1.unionFind( e.u, e.v );
            ans += e.w;
        }
    }
    if( d1.cnt[d1.findSet(0)] == m.size() ) {
        cout << ans << '\n';
    } else {
        cout << "Impossible\n";
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