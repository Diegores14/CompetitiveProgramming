#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, k=4;
	unsigned long long aux;
	cin >> t;
	while(t--){
		cout << "Quadrado da matriz #" << k++ << ":\n";
	 	cin >> n;
	 	vector<vector<string>> v(n, vector<string>(n));
	 	vector<int> tam(n,0);
		for(int i=0; i<n; i++){
		 	for(int j=0; j<n; j++){cin >> aux; v[i][j]=to_string(aux*aux);tam[j]=max(tam[j],(int)v[i][j].size());}			
		}
		for(int i=0; i<n; i++){			
		 	for(int j=0; j<n; j++){
		 	 	int x=tam[j]-v[i][j].size();
		 	 	for(int r=0; r<x; r++)cout << ' ';
		 	 	cout << v[i][j];
		 	 	cout << ((j!=n-1)? ' ': '\n');
		 	}
		}
		if(t)cout << '\n'; 
	}
	return 0;
}