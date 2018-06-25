#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, l, r;
	cin >> t;
	while(t--){
	 	cin >> l >> r;
		for (int i=0; i<l;i++){
		 	for (int j=0; j<r; j++){
				if(i==0){cout << "*";continue;}
				if(i==l-1){cout << "*";continue;}
				if(j==0){cout << "*";continue;}
				if(j==r-1){cout << "*";continue;}
				cout << ".";
			}
			cout << '\n';
		} 
		cout << '\n';
	}
	return 0;
}