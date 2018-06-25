#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	 	
	int v1, v2, D;
	while(cin >> v1, v1){
		cin >> D >> v2;
		int res = abs((D*v2*v1)/(v2-v1));
		cout << res << ((res==1)? " pagina" : " paginas") <<  '\n';
	}
	return 0;
}