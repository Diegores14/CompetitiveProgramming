#include <bits/stdc++.h>
using namespace std;
vector< vector<long long> > dp;

long long answer(int a, int b){
	if(dp[a][b]!=-1)return dp[a][b];
	if(b==1) return dp[a][b]=a*a;
 	long long cont = 0;
 	for(int i=0; i<a; i++){
 	 	cont += answer(a-1,b-1);
 	}
 	return dp[a][b] = cont;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, a, b;
	cin >> t;
	for(int k=1; k<=t; k++){
		cout << "Case " << k << ": ";
		cin >> a >> b;
		if(a<b || k==0) cout << "0\n";
		else{
		 	dp.assign(31, vector<long long>(31, -1));
		 	cout << answer(a, b) << '\n'; 
		}
	}
	return 0;
}