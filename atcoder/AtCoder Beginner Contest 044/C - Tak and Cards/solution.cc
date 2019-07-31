#include <bits/stdc++.h>
using namespace std;
const int tam = 51;
int n, a;
int v[tam];
long long dp[tam*tam][tam][tam];

long long solve(int sum, int idx, int cant) {
    if( idx == n ) return cant != 0 && sum%cant == 0 && sum/cant == a;
    long long &ans = dp[sum][idx][cant];
    if(ans != -1) return ans;
    ans = 0;
    ans += solve(sum, idx+1, cant);
    ans += solve(sum + v[idx], idx+1, cant+1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> a;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0) << '\n';
    return 0;
}