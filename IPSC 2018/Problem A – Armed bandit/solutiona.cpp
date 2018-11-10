#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux; 
	cin >> t;
	while(t--){
	 	cin >> n;
		for(int i=0; i<n; i++){
		 	cin >> aux;
			cout << aux << ((i!=n-1)? ' ': '\n');
		}
	}
	return 0;
}