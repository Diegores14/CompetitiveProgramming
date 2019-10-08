#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5+1;
double dp[tam];
vector<int> divisor[tam];

void precompute() {
    for( int i = 2; i < tam; i++ ) {
        for( int j = i; j < tam; j+= i ) {
            divisor[j].push_back( i );
        }
    }
    for( int i = 2; i < tam; i++ ) {
        dp[i] = 1;
        for( int j : divisor[i] ) {
            dp[i] += dp[ i/j ]+1;
        }
        dp[i] /= divisor[i].size();
    }
}

//void solve()

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    precompute();
    cout << fixed << setprecision(10);
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        cin >> n;
        cout << "Case " << cases << ": " << dp[n] << '\n';
    }
    return 0;
}