#include <bits/stdc++.h>
using namespace std;
int dp[101][100001];
int a[101];
int n;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> a[i];
    }
    for( int i = 0; i <= 100; i++ ) {
        dp[i][0] = 1;
    }
    vector< int > ans;
    for( int i = 1; i <= 100000; i++ ) {
        bool flag = false;
        for( int j = 1; j <= n; j++ ) {
            if((i-a[j] >= 0 && dp[j-1][i-a[j]]) || dp[j-1][i]) {
                dp[j][i] = 1;
                flag = true;
            }
        }
        if( flag ) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    while( ans.size() ) {
        cout << *ans.begin() << (ans.size() == 1? '\n' : ' ');
        ans.erase(ans.begin());
    }
    return 0;
}
