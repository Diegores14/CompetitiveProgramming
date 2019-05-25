#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int dp[17][1<<17];

int solve(int idx, int mask, vector< ii > &gold) {
    if(mask == (1<<gold.size())-1) {
        return max(abs(gold[0].first - gold[idx].first), abs(gold[0].second - gold[idx].second));
    }
    int &ans = dp[idx][mask];
    if(ans != -1) return ans;
    ans = 1e8;
    for(int i = 0; i < gold.size(); i++) {
        if( (mask&(1<<i)) == 0) {
            ans = min(ans, solve(i, mask|(1<<i), gold) + max(abs(gold[idx].first - gold[i].first), abs(gold[idx].second - gold[i].second) ));
        }
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, m, n;
    cin >> t;
    for(int cases = 1; cases <= t; cases++) {
        cin >> m >> n;
        string v[m];
        for(string &i : v) {
            cin >> i;
        }
        vector< ii > gold(1, make_pair(0, 0));
        for( int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 'x') {
                    gold[0] = make_pair(i, j);
                }
                if(v[i][j] == 'g') {
                    gold.push_back(make_pair(i, j));
                }
            }
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << cases << ": " << solve(0, 1, gold) << '\n';
    }
    return 0;
}