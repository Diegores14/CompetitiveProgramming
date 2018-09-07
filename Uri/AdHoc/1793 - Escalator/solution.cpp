#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, aux;
	while(cin >> n, n){
		int ans = 0;
	 	vector<int> v(1020, 0);
	 	for(int i=0; i<n; i++){
	 	 	cin >> aux;
	 	 	for(int j=aux-1; j<aux+9; j++){
	 	 	 	v[j]=1;
	 	 	}
	 	}
	 	for(int i=0; i<1020; i++) ans += v[i];
	 	cout << ans << '\n';
	}
	return 0;
}