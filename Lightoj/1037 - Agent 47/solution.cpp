#include <bits/stdc++.h>
using namespace std;
int dp[(1<<16)];
int n;
int calc[(1<<16)][15];
int v[15];
string weights[15];

int solve(int idx) {
    //cout << idx << ' ';
    if(idx == (1<<n)-1) {
        //cout << "hola\n";
        return 0;
    }
    int &ans = dp[idx];
    if(ans != -1) {
        return ans;
    }
    ans = 100000000;
    for(int i=0; i<n; i++) {
        if(((idx>>i)&1) == 0)
            ans = min(ans, solve( (idx|(1<<i)) ) + (v[i]+calc[idx][i]-1)/calc[idx][i]);
    }
    return ans;
}

void precalc() {
    for(int i=1; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            if((i>>j)&1)
                for(int k=0; k<n; k++)
                    calc[i][k] = max(calc[i][k], int(weights[j][k] -'0'));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    for(int k=1; k<=t; k++) {
        cout << "Case " << k << ": ";
        cin >> n;
        memset(dp, -1, sizeof dp);
        for(int i=0; i<(1<<n); i++) {
            for(int j=0; j<n; j++) {
                calc[i][j] = 1;
            }
        }
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        for(int i=0; i<n; i++) {
            cin >> weights[i];
        }
        precalc();
        cout << solve(0) << '\n';
    }
    return 0;
}