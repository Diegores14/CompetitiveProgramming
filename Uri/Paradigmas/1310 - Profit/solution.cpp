#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n, c, cont, aux;
	while(cin >> n >> c){
		cont = 0;
		vector<int> v(n);
	 	for(int i=0; i<n; i++)cin >> v[i];
		for(int i=0; i<n; i++){
			aux=0;
		 	for(int j=i; j<n; j++){
		 	 	aux+=(v[j]-c);
				cont = max(cont, aux);
			}
		}
		cout << cont << '\n';
	}
	return 0;
}