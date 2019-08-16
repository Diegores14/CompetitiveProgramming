#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;
long long mmax = 0;
const int tam = 1e5+5;
int n, f;
bool v[tam];
bool used[tam];
vector< vector< ii > > g;

long long DFS( int idx, long long sum = 0, int cost = 0 ) {
    used[idx] = true;
    long long suma = 0;
    for( ii &i: g[idx] ) {
        if(!used[i.first])
            suma += DFS( i.first, sum + i.second, i.second );
    }
    if( suma ) return suma + cost;
    if( v[idx] ) { mmax = max( mmax, sum); return cost; }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c;
    while( cin >> n >> f ) {
        memset( used, 0, sizeof used );
        memset( v, 0, sizeof v );
        mmax = 0;
        g.assign(n, vector< ii >());
        for( int i = 0; i < n-1; i++ ) {
            cin >> a >> b >> c; a--; b--;
            g[a].emplace_back( ii(b, c));
            g[b].emplace_back( ii(a, c));
        }
        for( int i = 0, tmp; i < f; i++ ) {
            cin >> tmp;
            tmp--;
            v[tmp] = true;
        }
        cout << DFS(0) - mmax << '\n';
    }
    return 0;
}