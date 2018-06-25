#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, maxi;
	cin >> n;
	while(n){
	 	vector <string> v(n);
		maxi=0;
		for(int i=0; i<n; i++){
			cin >> v[i];
			maxi = max(maxi, (int)v[i].size());
		}
		for(int i=0; i<n; i++){
		 	for(int j=maxi-v[i].size(); j>0; j--) cout << ' ';
			cout << v[i] << '\n';
		}
		cin >> n;
		if(n)cout << '\n';
	}
 	return 0;
}