#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int l,r, t;
	cin >> t; 
	while(t--){
		cin >> l >> r;
		for(int i=0; i<l; i++){
			for(int j=0; j<r; j++){
				if((i+j)%2) cout << ".";
				else cout << "*";
			}
		cout << '\n';
		}
		cout << '\n';
	}
	return 0;

}