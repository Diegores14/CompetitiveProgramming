#include <bits/stdc++.h>
using namespace std;
int dp[201][20];
int t, n, m, k;

int solution(vector< vector<int> > &v, int g, int money){
    if(money<0)
        return -10000000;
    if(g == n){
        return m - money;
    }
    int &ans = dp[money][g];
    if(ans != -1)
        return dp[money][g];
    for(int i: v[g]){
        ans = max(ans, solution(v, g+1, money - i));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin >> m >> n;
        vector< vector<int> > v(n);
        for(int i = 0; i<n; i++){
            cin >> k;
            v[i].assign(k, 0);
            for(int j=0; j<k; j++){
                cin >> v[i][j];
            }
        }
        int ans = solution(v, 0, m);
        if(ans < 0){
            cout << "no solution\n";
        }else{
            cout << ans << '\n';
        }
    }
    return 0;
}