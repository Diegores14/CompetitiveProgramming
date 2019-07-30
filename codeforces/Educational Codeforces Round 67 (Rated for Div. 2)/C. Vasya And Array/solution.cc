#include <bits/stdc++.h>
using namespace std;
typedef pair < int, int > ii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, r, t;
    int n, m; 
    cin >> n >> m;
    vector< ii > queries[2];
    for(int i = 0; i < m; i++) {
        cin >> t >> l >> r;
        queries[t].push_back( ii(l-1, r-1) );
    }
    int right = 0;
    int ans[n];
    int val = 1e5+1;
    sort( queries[1].begin(), queries[1].end() );
    for(auto &i: queries[1] ) {
        while( right <= i.first ) {
            --val;
            ans[right++] = val;
        }
        while( right <= i.second ) {
            ans[right++] = val;
        }
    }
    while(right < n) {
        --val;
        ans[right++] = val;
    }
    for(auto &i : queries[0]) {
        if( ans[i.first] <= ans[i.second] ) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ((i == n-1)? '\n' : ' ');
    }
    return 0;
}