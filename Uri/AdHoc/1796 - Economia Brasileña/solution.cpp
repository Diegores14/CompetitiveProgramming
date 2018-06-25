#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,aux,sum=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> aux;
		if(!aux)sum++; 
	}
	cout << ((sum>n/2)? "Y\n" : "N\n");
 	return 0;
}