#include <bits/stdc++.h>
using namespace std;
int dp[201][20];
int t, k, n, m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector< vector<int> > v(n);
        for(int i = 0; i<n; i++){
            cin >> k; 
            v[i].assign(k, 0);
            for(int j=0; j<k; j++){
                cin >> v[i][j];
            }
        }
        memset(dp, 0, sizeof dp);
        for(int i: v[0]){
            if(m-i >= 0){
                dp[m-i][0] = 1;
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<201; j++){
                if(dp[j][i] == 1){
                    for(int k : v[i+1]){
                        if(j-k >=0){
                            dp[j-k][i+1] = 1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(; ans < 201; ans++){
            if(dp[ans][n-1]){
                break;
            }
        }
        if(ans == 201){
            cout << "no solution\n";
        }else{
            cout << m - ans << '\n';
        }
    }
    return 0;
}