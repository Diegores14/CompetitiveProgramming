#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b, cost; 
    cin >> n;
    long long sum = 0;
    vector< vector< ii > > G(n);
    for( int i = 0; i < n; i++ ) {
        cin >> a >> b >> cost; a--; b--;
        sum += cost;
        G[a].emplace_back( ii(b, 0) );
        G[b].emplace_back( ii(a, cost) );
    }
    bool used[n];
    memset( used, 0, sizeof used );
    int cur = 0;
    long long sum1 = 0;
    used[0] = true;
    while( !used[ G[cur][0].first ] || !used[ G[cur][1].first ] ) {
        if( !used[G[cur][0].first] ) {
            used[G[cur][0].first] = true;
            sum1 += G[cur][0].second;
            cur = G[cur][0].first;
        } else {
            used[G[cur][1].first] = true;
            sum1 += G[cur][1].second;
            cur = G[cur][1].first;
        }
    }
    if( G[cur][0].first  == 0 ) {
        sum1 += G[cur][0].second;
    } else {
        sum1 += G[cur][1].second;
    }
    cout << min( sum1, sum-sum1 ) << '\n';
    return 0;
}