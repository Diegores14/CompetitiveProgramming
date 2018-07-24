#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, aux;
	bool res;
	while(cin >> n >> m, n || m){
	 	vector<int> v(n,0);
	 	res=false;
		for(int j=1; j<=m; j++)
			for(int i=0; i<n; i++){ cin >> aux; v[i]+=aux; if(j==m && v[i]==m)res=true;}
		cout << ((res)? "yes\n" : "no\n");
	}
 	return 0;
}