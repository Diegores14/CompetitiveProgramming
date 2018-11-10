#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux;
	cin >> t;
	while(t--){
	 	cin >> n;
		vector<long long> prefix(n+1, 0);
		for(int i=1; i<=n; i++){
		 	cin >> aux;
			prefix[i] = prefix[i-1]+aux;
		}
		int ans = 0;
		long long i=1;
		while(i<n){
		 	ans++;
			i = i + prefix[i];
		}
		cout << ans << '\n';
	}
	return 0;
}