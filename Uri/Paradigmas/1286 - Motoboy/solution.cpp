#include <bits/stdc++.h>
using namespace std;

int calculo(vector<int> &v, vector<int> &wt, int W, int n){
        int dp[n+1][W+1];

	for(int i=0; i<=n; i++){
	 	for(int j=0; j<=W; j++){
	 	 	if(i==0 || j==0) dp[i][j]=0;
			else if(wt[i-1] <= j)
				dp[i][j] = max(v[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}
 	return dp[n][W];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, w;
	while(cin >> n, n){ 
		vector<int> v(n),wt(n);
	        cin >> w;
		for(int i=0; i<n; i++)cin >> v[i] >> wt[i];
		cout << calculo(v, wt, w, v.size()) << " min.\n";
	}        
 	return 0;
}