#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n){
		vector<int> v(n);
		long long aux=0, aux1=0;
		for(int i=0; i<n; i++){ cin >> v[i];aux+=v[i];}
		if(aux%n==0){
			aux/=n;
		 	for(int i=0; i<n; i++)aux1+=abs(v[i]-aux); 
		 	cout << aux1/2 +1 << '\n';
		}
		else cout << "-1\n";
	}
	return 0;
}