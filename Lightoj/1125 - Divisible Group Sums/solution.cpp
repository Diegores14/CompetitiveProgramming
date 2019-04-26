#include <bits/stdc++.h>
using namespace std;
long long dp[205][21][11];
long long v[205];
int n, m, d;

long long solve(int idx, int mod, int cant) {
    if(cant == 0) 
        return mod? 0 : 1;
    if(idx ==  n) return 0;
    long long &ans = dp[idx][mod][cant];
    if(ans != -1) {
        return ans;
    }
    int mmod = (mod+v[idx]%d)%d;
    if(mmod < 0) {
        mmod += d;
    }
    ans = solve(idx+1, mmod, cant-1) + solve(idx+1, mod, cant);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, q;
    cin >> t;
    for(int k=1; k <= t; k++) {
        cout << "Case " << k << ":\n";
        cin >> n >> q;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        while(q--) {
            memset(dp, -1, sizeof dp);
            cin >> d >> m;
            cout << solve(0, 0, m) << '\n';
        }
    }
    return 0;
}