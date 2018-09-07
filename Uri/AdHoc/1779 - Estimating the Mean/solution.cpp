#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n;
	int pro;
	cin >> t;
	for(int k=1; k<=t; k++){
		cin >> n;
		cout << "Caso #" << k << ": ";
		int ans=0;
		pro=0;    
		vector<int> v(n);
		for(int i=0; i<n; i++){ cin >> v[i]; pro = max(v[i],pro);}
	 	for(int i=0; i<n; i++){
	 		int aux=0;
	 	 	for(int j=i; j<n && v[j]==pro; j++){aux++; i=j;}
	 	 	ans = max(ans, aux);
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}