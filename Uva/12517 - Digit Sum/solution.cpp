#include <bits/stdc++.h>
using namespace std;

long long dp[11][2][91];

long long f(int idx, bool top, int acc, const string & s){
	if(dp[idx][(int)top][acc]!=-1) return dp[idx][(int)top][acc];
	if(idx==(int)s.size()) return dp[idx][(int)top][acc] = acc;
	long long cont=0;
	int num = (top? s[idx]-'0' : 9);
	for(int i=0; i<=num; i++){
		cont += f(idx+1, top && s[idx]-'0'==i, acc+i, s);
	}
	return dp[idx][(int)top][acc] = cont;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string a;
	int b;
	while(cin >> b >> a, a!="0" || b){
	 	memset(dp, -1, sizeof dp);
		long long ans = f(0, true, 0, a);
		string s = to_string(b-1);
		memset(dp, -1, sizeof dp);
		ans -= f(0, true, 0, s);
		cout << ans << '\n';
	}
	return 0;
}