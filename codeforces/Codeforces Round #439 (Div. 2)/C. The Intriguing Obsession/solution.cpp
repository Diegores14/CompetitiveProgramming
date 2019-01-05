#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int binomial[5001][5001];
int permutation[5001];

int solve(int a, int b){
    int res = 0;
    for(int k=0; k <= a && k <= b; k++){
        long long temp = permutation[k];
        temp = (temp * binomial[a][k])%M; 
        temp = (temp * binomial[b][k])%M;
        res = (res + temp)%M;
    }
    return res;
}

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c;
    memset(binomial, 0, sizeof binomial);
    binomial[0][0] = 1;
    for(int i=1; i<=5000; i++){
        binomial[i][0] = 1;
        for(int j=1; j<=i; j++){
            //cout << i << ' ' << j << '\n';
            binomial[i][j] = (binomial[i-1][j-1] + binomial[i-1][j])%M;
        }
    }
    permutation[0] = 1;
    for(int i=1; i<=5000; i++){
        permutation[i] = (1LL * permutation[i-1] * i)%M;
    }
    cin >> a >> b >> c;
    int ans = 1;
    ans = (1LL * ans * solve(a,b))%M;
    ans = (1LL * ans * solve(c,b))%M;
    ans = (1LL * ans * solve(a,c))%M;
    cout << ans << '\n';
    return 0;
}