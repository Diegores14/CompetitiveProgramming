#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
	 	cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++){
		 	cin >> v[i];
		}
		bool ans = false;
		int aux = 0, cont=0;
		for(int i=0; i<n; i++){
		 	if(aux <= v[i]) cont++;
			else{
				cont = 1;
			}
			aux = v[i];
			if(cont == n){
			 	ans = true;
				break;
			}
		}
		for(int i=0; i<n; i++){
		 	if(aux <= v[i]) cont++;
			else{              
				cont = 1;
			}
			aux = v[i];
			if(cont == n){
			 	ans = true;
				break;
			}
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}