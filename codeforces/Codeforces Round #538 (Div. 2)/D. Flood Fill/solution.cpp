#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int n;
vector<int> l, r, v;

int solution(int i, int j) {
    if(i == 0 && j == n-1) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int &ans = dp[i][j];
    if(0<i && j<n-1 && v[i-1] == v[j+1]) {
        return ans = solution(l[i-1], r[j+1]) + 1;
    }
    ans = 1000000000;
    if(0<i) {
        ans = min(ans, solution(l[i-1], j) + 1);   
    }
    if(j<n-1) {
        ans = min(ans, solution(i, r[j+1]) + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    v.assign(n, 0); 
    l.assign(n, 0);
    r.assign(n, n-1);
    for(int &i: v) {
        cin >> i;
    }
    memset(dp, -1, sizeof dp);
    int ans = 1e9;
    for(int i=1; i<n; i++) {
        if(v[i-1] != v[i]) {
            l[i] = i;
        } else {
            l[i] = l[i-1];
        }
        if(v[n-i-1] != v[n-i]) {
            r[n-i-1] = n-i-1;
        } else {
            r[n-i-1] = r[n-i];
        }
    }
    for(int i=0; i<n; i++) {
        ans = min(ans, solution(l[i], r[i]));
        // cout << l[i] << ' ' << r[i] << ' ' << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}