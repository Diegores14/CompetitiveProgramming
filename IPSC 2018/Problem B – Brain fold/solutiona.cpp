#include <bits/stdc++.h>
using namespace std;
	
int binpow(int n, int b){
	int res = 1;
	while(b>0){
	 	if(b&1)
			res = (res*n)%1000000007;
		n = (n*n)%1000000007;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	char c;
	cin >> t;
	while(t--){
		vector<int> v(2, 0);
	 	cin >> n;
		for(int i=0; i<n; i++){
		 	cin >> c;
			if(c=='T' || c=='B')
				v[0]++;
			else
				v[1]++;
		}
		string s;
		cin >> s;
		if(s=="TB" || s=="BT")
			cout << binpow(2, v[1]) + 1 << '\n';
		else
			cout << binpow(2, v[0]) + 1 << '\n';
	}
	return 0;
}