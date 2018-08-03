#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long answer(vector<vector<int>> & v, vector<vector<int>> & d){
	for(int i=1; i<(int)v.size(); i++){
		dp[i%2][v[i].size()]=1000000000000;
	 	for(int j=0; j<(int)v[i].size(); j++){
	 		dp[i%2][j] = min(dp[(i-1)%2][j]+((v[i][j]-d[i-1][j]<=0)? 0 : v[i][j]-d[i-1][j]), v[i][j]+dp[(i-1)%2][v[i].size()]);
	 	 	dp[i%2][v[i].size()]= min(dp[i%2][v[i].size()], dp[i%2][j]);
	 	}
	}
	return dp[(v.size()-1)%2][v[0].size()];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, m;
	cin >> t;
	while(t--){
	 	cin >> n >> m;
	 	vector<vector<int>> v(n, vector<int>(m, 0)), d(n, vector<int>(m, 0));
	 	dp.assign(2, vector<long long>(m+1, 0));dp[0][m] = 1000000000;
	 	for(int i=0; i<n; i++)
	 		for(int j=0; j<m; j++)cin >> v[i][j];
	 	for(int i=0; i<n; i++)
	 		for(int j=0; j<m; j++)cin >> d[i][j];
		for(int i=0; i<m; i++){dp[0][m] = min(dp[0][m],(long long)v[0][i]);dp[0][i]=v[0][i];}
	        cout << answer(v, d) << '\n';
	}
 	return 0;
}