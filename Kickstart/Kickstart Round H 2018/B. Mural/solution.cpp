#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int k=1; k<=t; k++){
	 	cout << "Case #" << k << ": ";
		cin >> n;
	 	int tam = n/2 + (n&1);
	 	long long ans = 0, sum = 0;
	 	string s;
	 	cin >> s;
	 	for(int i=0; i<tam; i++){
	 	 	sum += s[i] - '0';
	 	}
	 	ans = sum;
	 	for(int i=tam; i<n; i++){
			sum += (s[i] - '0') - (s[i-tam] - '0');
			ans = max(ans, sum);
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}