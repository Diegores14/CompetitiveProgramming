#include <bits/stdc++.h>
using namespace std;

int dp[10][2][91][91];

int f(int idx, bool top, int residuo, int acc, const string &s, const int &k){
	if(idx==(int)s.size()) return ((residuo==0 && (acc%k)==0)? 1 : 0);
	if(dp[idx][(int)top][residuo][acc]!=-1)return dp[idx][(int)top][residuo][acc];
	int cont = 0;
	int mmax = (top? s[idx]-'0' : 9);
	for(int i=0; i<=mmax; i++)
		cont += f(idx+1, top && mmax==i, (residuo*10+i)%k, acc+i, s, k);
	return dp[idx][(int)top][residuo][acc] = cont;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string b;
	int a, k, n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a >> b >> k;
		if(k>90) cout << "Case " << i << ": 0" << '\n';
		else{
			stringstream aux;
			memset(dp, -1, sizeof dp);
			int ans = f(0,true, 0, 0, b, k);
	 		aux << (a-1);
			string s;
			aux >> s;
			memset(dp, -1, sizeof dp);
			ans -= f(0,true, 0, 0, s, k);
			cout << "Case " << i << ": " << ans << '\n';
		}
	}
	return 0;
}