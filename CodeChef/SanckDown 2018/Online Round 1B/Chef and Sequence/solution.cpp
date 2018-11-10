#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, k, aux;
	cin >> t;
	while(t--){
		int cont=0;
		cin >> n >> k;
		for(int i=0; i<n; i++){
		 	cin >> aux;
			if(aux>1) cont++;
		}
		if(cont<=k)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}