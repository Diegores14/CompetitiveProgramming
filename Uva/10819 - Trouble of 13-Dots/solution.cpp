#include <bits/stdc++.h>
using namespace std;
int m, n;
int v[2][100], dp[10201][101];

int solution(int idx, int money){
    if(money > m && m < 1800)
        return -1000000;
    if(money > m+200)
        return -1000000;
    if(n == idx){
        if(money > m && money <= 2000)
            return -1000000;
        return 0;
    }
    int &ans = dp[money][idx];
    if(ans != -1)
        return ans;
    ans = max(v[1][idx] + solution(idx+1, money + v[0][idx]), solution(idx+1, money));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(cin >> m >> n){
        for(int i=0; i<n; i++){
            cin >> v[0][i] >> v[1][i];
        }
        memset(dp, -1, sizeof dp);
        cout << solution(0, 0) << '\n';
    }
    return 0;
}