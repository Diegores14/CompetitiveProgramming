#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for( int i = 0; i < n; i++ ) cin >> a[i];
    vector< ii > dp[20];
    int cur = 1;
    for( int i = 0; i < n; i++ ) dp[0].emplace_back( ii(a[i], 0) );
    for( int grad = 1; grad < 20; grad++ ) {
        cur <<= 1;
        for( int j = 0; j + cur <= n; j++) {
            int left = dp[grad-1][j].first;
            int right = dp[grad-1][j+cur/2].first;
            int sum = (left + right)%10;
            int leftCandies = dp[grad-1][j].second;
            int rightCandies = dp[grad-1][j+cur/2].second;
            int ansCandies = leftCandies + rightCandies;
            if(left + right >= 10) ansCandies++;
            dp[grad].emplace_back( ii(sum, ansCandies) );
        }
    }
    int q, l, r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        //cout << "Hello\n";
        int ran = r - l + 1;
        int grad = 0;
        while( 1<<grad < ran ) grad++;
        //cout << grad << " Hello\n";
        cout << dp[grad][l-1].second << '\n';
    }
    return 0;
}