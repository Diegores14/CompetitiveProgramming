#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long t, n, m, k, l;
	cin >> t;
	while(t--){
	 	cin >> n >> m >> k >> l;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
		 	cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long ans = 1000000000000;
		for(int i=0; i < n; i++){
		 	ans = min(ans, (m - (v[i]/l) + i + 1)*l - (v[i]%l));
		}
		ans = min(ans, (m - (k/l) + n + 1)*l - (k%l));
		if(ans>0)
			cout << ans << '\n';
		else
			cout << "0\n";
	}
	return 0;
}