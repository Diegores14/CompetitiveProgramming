#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long t, a, b, k;
	cin >> t;
	while(t--){
		long long ans = 0;
	 	cin >> a >> b >> k;
	 	int cant = (k+1)>>1;
	 	ans += a*cant;
	 	ans -= b*(k-cant);
	 	cout << ans << '\n';
	}
	return 0;
}