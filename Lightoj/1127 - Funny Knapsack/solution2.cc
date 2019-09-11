#include <bits/stdc++.h>
using namespace std;
int n, w, limit;
bool turn;
int v[35];
vector< int > s[2];

void preCal( int idx, long long sum ) {
    if( sum > w ) return;
    if( idx == limit ) {
        s[turn].push_back( sum );
        return;
    }
    preCal( idx+1, sum );
    preCal( idx+1, sum + v[idx] );
}

int bs( int x ) {
    long long l = -1, r = s[1].size();
    while( r-l != 1 ) {
        int mid = (l+r)/2;
        if( x < s[1][mid] ) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        s[0].clear(); s[1].clear();
        cin >> n >> w;
        for( int i = 0; i < n; i++ ) {
            cin >> v[i];
        }
        limit = n/2;
        turn = 0;
        preCal( 0, 0 );
        limit = n;
        turn = 1;
        preCal( n/2, 0 );
        sort( s[1].begin(), s[1].end() );
        long long ans = 0;
        for( int i = 0; i < s[0].size(); i++ ) {
            ans += bs( w - s[0][i] );
        } 
        cout << "Case " << cases << ": " << ans << '\n';
    }
    return 0;
}