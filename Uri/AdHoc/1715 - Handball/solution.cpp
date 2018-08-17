#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int n, m, ans, aux;
	bool res;
	while(cin >> n >> m){
		ans=0;
	 	for(int i=0; i<n; i++){
	 		res=true;
	 	 	for(int j=0; j<m; j++){
	 	 	 	cin >> aux;
	 	 	 	if(aux==0)res=false;
	 	 	}
	 	 	ans+=res;
	 	}
	 	cout << ans << '\n';
	}
 	return 0;
}