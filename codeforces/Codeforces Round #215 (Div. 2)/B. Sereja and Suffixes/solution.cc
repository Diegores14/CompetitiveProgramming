#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5 + 5;
bool used[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(used, 0, sizeof used);
    int n, m, temp;
    cin >> n >> m;
    int v[n], dp[n+1];
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        dp[i] = (!used[v[i]]) + dp[i+1];
        used[v[i]] = true;
    }
    while(m--) {
        cin >> temp;
        cout << dp[temp-1] << '\n';
    }
    return 0;
}