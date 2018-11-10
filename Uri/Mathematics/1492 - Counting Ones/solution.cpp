#include <bits/stdc++.h>
using namespace std;
long long dp[60][60][2];

long long dptop(long long n, int idx, int unos, bool isTop){
	if(idx == -1) return unos;
	if(dp[idx][unos][isTop]!=-1)return dp[idx][unos][isTop];
	int limit = (isTop)? (n>>idx)&1 : 1;
	long long ans = 0;
	for(int i=0; i<=limit; i++){
		ans += dptop(n, idx-1, unos + ((i==1)? 1 : 0), isTop && i==limit);
	}
	return dp[idx][unos][isTop] = ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long a, b;
	while(cin >> a >> b){
		memset(dp, -1, sizeof dp);
		long long primero = dptop(b, 55, 0, true);
		memset(dp, -1, sizeof dp);
		cout << primero - dptop(a-1, 55, 0, true) << '\n';
	}
	return 0;
}