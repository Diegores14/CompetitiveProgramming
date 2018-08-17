#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, aux, salto, ans;
	while(cin >> n){
		ans=0;
		vector<int> v(n+1, 0);
		set<int> s;
	 	for(int i=1; i<=n; i++){ cin >> aux; v[i] = v[i-1] + aux; s.insert(v[i]);}
		if(v[n]%3) cout << "0\n";
		else{                               
			salto = v[n]/3;
		 	for(int i=1; i<=n && v[i]<=salto; i++)if(s.count(v[i]+salto) && s.count(v[i]+2*salto)) ans++;
		 	cout << ans << '\n';
		}
	}
	return 0;
}