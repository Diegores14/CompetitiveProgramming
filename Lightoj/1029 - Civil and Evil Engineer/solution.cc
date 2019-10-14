#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    int n;
    vector< int > p;
    DisjointSet( int n ): n(n), p(n) {
        for( int i = 0; i < n; i++ ) {
            p[i] = i;
        }
    }
    int findSet( int i ) { return ( (i == p[i])? i : (p[i] = findSet(p[i])) ); }
    bool isSame( int i, int j ) { return findSet(i) == findSet(j); }
    void unionSet( int i, int j ) {
        int x = findSet( i ), y = findSet( j );
        if( x != y ) {
            p[x] = y;
        }
    }
};

struct edge{
    int u, v, w;
    edge() {}
    edge( int u, int v, int w ): u(u), v(v), w(w) {}
    bool operator <( edge other ) const {
        return w < other.w;
    }
};

long long gcd( long long a, long long b ) {
    return b? gcd(b, a%b) : a;
}

void solve() {
    int n, u, v, w;
    cin >> n;
    DisjointSet d1(n+1), d2(n+1);
    vector< edge > E;
    while( cin >> u >> v >> w, u || v || w ) {
        E.push_back( edge(u, v, w) );
    }
    sort( E.begin(), E.end() ); 
    long long  sum1 = 0, sum2 = 0;
    for( int i = 0; i < E.size(); i++ ) {
        if( !d1.isSame(E[i].u, E[i].v) ) {
            sum1 += E[i].w;
            d1.unionSet( E[i].u, E[i].v );
        }
        if( !d2.isSame(E[E.size()-i-1].u, E[E.size()-i-1].v) ) {
            sum2 += E[E.size()-i-1].w;
            d2.unionSet( E[E.size()-i-1].u, E[E.size()-i-1].v );
        }
    }
    long long sum = sum1 + sum2;
    long long d = gcd( sum , 2 );
    if( d == 2 ) {
        cout << sum/d << '\n';
    } else {
        cout << sum << '/' << 2 << '\n';
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