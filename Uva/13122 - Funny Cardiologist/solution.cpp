#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

double dp[260][260];

double dist(pair<int,int> x, pair<int,int> y){
	return sqrt((x.first-y.first)*(x.first-y.first) +(x.second-y.second)*(x.second-y.second));
}

double f(int i, int k, vector<ii> & v){
	if(dp[i][k]!=-1) return dp[i][k];
	if((i+1)==(int)v.size())return ((k==0)? 0 : 2000000);
	double mmin = 2000000;	                                                                  
	for(int j=0; j<=k && (j+i+1)<(int)v.size(); j++){
	 	mmin = min(mmin, dist(v[i], v[i+j+1]) + f(i+j+1, k-j, v));
	}
	return dp[i][k] = mmin;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cout << fixed << setprecision(3);
	while(cin >> n >> k){
		for(int i=0; i<260; i++)
			for(int j=0; j<260; j++)
				dp[i][j]=-1;
		vector<pair<int, int>> v(n);
	 	for(int i=0; i<n; i++){
	 	 	cin >> v[i].first >> v[i].second;
		}
		
		cout << f(0, k, v) << '\n';
	}
	return 0;
}