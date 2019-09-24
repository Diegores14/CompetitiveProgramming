#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
long long x[tam];
int p[tam];
list< int > G[tam];
map< long long, long long > dp[tam];
const int mod = 1e9+7;

void dfs( int idx, int par ) {
    p[idx] = par;
    for( int &i: G[idx] ) {
        if( i == par ) continue;
        dfs(i, idx);
    }
}

long long gcd( long long a, long long b ) {
    return b? gcd(b, a%b) : a;
}

long long solve( long long idx, long long d ) {
    if( dp[idx].count(d) )  return dp[idx][d];
    long long &ans = dp[idx][d];
    ans = d%mod;
    for( int &i: G[idx] ) {
        if( i == p[idx] ) continue;
        ans = (ans+solve( i, gcd(d, x[i])))%mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a, b;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> x[i];
    }
    for( int i = 1; i < n; i++ ) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 1);
    long long ans = 0;
    for( int i = 1; i <= n; i++ ) {
        ans = (ans+solve(i, x[i]))%mod;
    }
    cout << ans << '\n';
    return 0;
}