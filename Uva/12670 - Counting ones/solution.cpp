#include <bits/stdc++.h>
using namespace std;

long long dp[56][2][56];

long long f(int idx, bool top, int acc, const string & s){
	if(dp[idx][(int)top][acc]!=-1) return dp[idx][(int)top][acc];
	if((int)s.size()==idx) return dp[idx][(int)top][acc] = acc;
	long long cont=0;
	int num = (top? s[idx]-'0': 1);
	for(int i=0; i<=num; i++){
	 	cont += f(idx+1, top && (i==(s[idx]-'0')), acc+(1==i), s); 
	}
	return dp[idx][(int)top][acc] = cont;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long a, b;
	while(cin >> a >> b){
		string s = bitset<54>(b).to_string();
		memset(dp, -1, sizeof dp);
		long long ans = f(0, true, 0, s);
		s = bitset<54>(a-1).to_string();
		memset(dp, -1, sizeof dp);
		ans -= f(0, true, 0, s);
		cout << ans << '\n';
	}
	return 0;
}