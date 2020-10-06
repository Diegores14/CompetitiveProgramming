#include <bits/stdc++.h>
using namespace std;
const int tam = 1e6+10;
int dp[tam];
int INF = 1e9;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    for( int i = 1; i < tam; i++ ) {
        dp[i] = INF;
    }
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        for( char c: to_string(i) ) {
            int x = c-'0';
            if(0 <= i-x) {
                dp[i] = min( dp[i], dp[i-x]+1);
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
