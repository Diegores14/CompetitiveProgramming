#include <bits/stdc++.h>
using namespace std;
const int tam = 105, len = tam*tam;
double dp[tam][len];
double pr[tam];
int x[tam];
int n, m;
double p;

void solve() {
    cin >> p >> n;
    long long ans = 0, sum = 0;
    for( int i = 1; i <= n; i++ ) {
        cin >> x[i] >> pr[i];
        sum += x[i];
    }
    for( int i = 1; i <= sum; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            if( i < x[j] ) {
                dp[j][i] = dp[j-1][i];
            } else {
                dp[j][i] = min( dp[j-1][i], pr[j] + (1 - pr[j])*dp[j-1][i-x[j]] );
            }
        }
        if( dp[n][i] < p ) {
            ans = i;
        }
    }
    cout << ans << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    for( int i = 0; i < len; i++ ) {
        dp[0][i] = 2;
    }
    for( int i = 0; i < tam; i++ ) {
        dp[i][0] = 0;
    }
    int t;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}