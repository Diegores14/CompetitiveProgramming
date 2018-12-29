#include <bits/stdc++.h>
using namespace std;
long long v[200];
int n, q, d, m;
long long dp[21][11][201];

long long solution(int idx, int money, int cant){
    if(money < 0){
        money += d;
    }
    if(cant == 0){
        return (money == 0? 1 : 0);
    }
    if(idx == n){
        return 0;
    }
    long long &ans = dp[money][cant][idx];
    if(ans != -1)
        return ans;
    ans = solution(idx+1, (money + v[idx])%d, cant-1) + solution(idx+1, money, cant);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k = 1;
    while(cin >> n >> q, n || q){
        cout << "SET " << k++ << ":\n";
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=1; i<=q; i++){
            memset(dp, -1, sizeof dp);
            cin >> d >> m;
            cout << "QUERY " << i << ": " << solution(0, 0, m) << '\n';
        }
    }
    return 0;
}