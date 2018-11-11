#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
	 	long long ans = 0;
		long long a, b, c;
		for(int i=0; i<n; i++){
			cin >> a >> b >> c;
			ans += a*c;
		}
		cout << ans << '\n';
	}
	return 0;
}