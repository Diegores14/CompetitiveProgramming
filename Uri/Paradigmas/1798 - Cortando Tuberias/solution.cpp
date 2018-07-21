#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[1001][2001]; 


int answer(vector<pii> & a,int t,int i){
	if(i>=(int)a.size() || t<=0) return 0;
	if(dp[i][t] != -1)return dp[i][t];
	int best=0;
	for(int j=0; j*a[i].first<=t; j++){
		best = max(best, answer(a, t-j*a[i].first, i+1)+j*a[i].second);
	}
	return dp[i][t] = best;
}

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, t, aux1, aux2;
	while(cin >> n >> t){
	 	vector<pii> v(n);
	 	for(int i=0; i<n; i++){ cin >> aux1 >> aux2; v[i]=pii(aux1,aux2);}
		memset(dp, -1, sizeof dp);
		cout << answer(v, t, 0) << '\n';
	}	
 	return 0;
}