#include <bits/stdc++.h>
using namespace std;
int v[20];
int n, k, limit, pos;
vector< int > s[2];

void precal(int idx = 0, int sum = 0) {
    if( sum > k ) return;
    if( idx == limit) {
        s[pos].push_back( sum );
        return;
    }
    precal(idx+1, sum );
    precal(idx+1, sum + v[idx]);
    precal(idx+1, sum + v[idx] + v[idx]);
}

bool bs( int x ) {
    int l = 0, r = s[1].size();
    while( r-l != 1 ) {
        int mid = (l+r)/2;
        if( s[1][mid] <= x ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return s[1][l] == x;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    for( int cases = 1; cases <= t; cases++ ) {
        s[1].clear(); s[0].clear();
        scanf("%d %d", &n, &k);
        for( int i = 0; i < n; i++ ) {
            scanf("%d", &v[i]);
        }
        limit = n/2;
        pos = 0;
        precal(0);
        limit = n;
        pos = 1;
        precal(n/2);
        sort( s[1].begin(), s[1].end() );
        bool ans = false;
        for( int i = 0; i < s[0].size(); i++ ) {
            if( bs( k - s[0][i] ) ) {
                ans = true; break;
            }
        }
        if( ans ) {
            printf("Case %d: Yes\n", cases);
        } else {
            printf("Case %d: No\n", cases);
        }
    }
    return 0;
}