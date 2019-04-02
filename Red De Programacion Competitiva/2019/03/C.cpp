#include <bits/stdc++.h>
using namespace std;

long long mod = 998244353;
long long n, k, dp[1005][1005]; 
int a[1005];

long long go(int i, int k, int ant){
    if(i == n || k <= 0)return (k == 0 ? 1 : 0);
    if(ant == a[i]) {
        return go(i+1, k, ant);
    }
    if(dp[i][k] != -1)return dp[i][k];
    long long ans = (go(i+1, k-1, a[i]) + go(i+1, k, ant)) % mod;
    return dp[i][k] = ans;
} 

int main(){
    int x;
    while(cin >> n >> k){
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        memset(dp, -1, sizeof dp);
        cout << go(0, k, -1) << endl;
    }
    return 0;
}