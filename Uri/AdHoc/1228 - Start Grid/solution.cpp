#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, ans;
	while(cin >> n){
		ans=0;
	 	vector<vector<int>> v(2, vector<int>(n));
	 	for(int i=0; i<n; i++) cin >> v[0][i];
	 	for(int i=0; i<n; i++) cin >> v[1][i];
	 	for(int i=0; i<n; i++){
	 	 	if(v[0][i] != v[1][i]){
	 	 		int j;
	 	 	 	for(j=i; j<n; j++)if(v[0][j] == v[1][i])break;
	 	 	 	for(int k=j; k>i && k!=n; k--){ans++;swap(v[0][k-1], v[0][k]);}
	 	 	}
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}