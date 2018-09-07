#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > dp;

int answer(vector< vector<int> > & v, int i, int j){
	if(j==-1 || j==(int
	)v[i].size()) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==(int)v.size()-1) return v[i][0];
	if(v[i].size()>v[i+1].size()){
	 	dp[i][j] = v[i][j] + max(answer(v, i+1, j-1), answer(v, i+1, j));
	}else{
	 	dp[i][j] = v[i][j] + max(answer(v, i+1, j), answer(v, i+1, j+1));
	}
	return dp[i][j];
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int k=1; k<=t; k++){
	 	cin >> n;	 	
	 	vector< vector<int> > v(2, vector<int>(n, 0)), data;
	 	for(int i=1; i<=n; i++){
	 	        data.push_back(vector<int>(i));
			for(int j=0; j<i; j++){
			 	cin >> data[i-1][j];

			}
	 	}
	 	for(int i=n-1; i>0; i--){
	 	        data.push_back(vector<int>(i));
			for(int j=0; j<i; j++){
			 	cin >> data[data.size()-1][j];
				
			}
	 	}
	 	dp.assign(200, vector<int>(200, -1));
	 	cout << "Case " << k << ": " << answer(data, 0, 0) << '\n';
	 	}
 	return 0;
}