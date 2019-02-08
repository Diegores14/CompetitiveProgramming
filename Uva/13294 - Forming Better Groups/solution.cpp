#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > groups;
int n, d;
long long dp[1<<22];

int position(int n) {
    int i = 0;
    while( (n>>i)&1 ) {
        i++;
    }
    return i;
}

long long solution(int idx, int acum) {
    if(idx == n) {
        return 1;
    }
    long long &ans = dp[acum];
    if(ans != -1) {
        return ans;
    }
    ans = 0;
    for(int i: groups[idx]) {
        if((acum&i) == 0) {
            ans += solution(position(acum^i), acum^i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> n >> d, n || d) {
        vector<int> v(n);
        groups.assign(n, vector<int>());
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        for(int i=0; i<n-2; i++) {
            for(int j=i+1; j<n-1; j++) {
                for(int k=j+1; k<n; k++) {
                    if(max(v[i], max(v[j], v[k])) - min(v[i], min(v[j], v[k])) <= d) {
                        int temp = (1<<i) | (1<<j) | (1<<k);
                        groups[i].emplace_back(temp);
                    }
                }
            }
        }
        memset(dp, -1, sizeof dp);
        cout << solution(0, 0) << '\n';
    }
    return 0;
}