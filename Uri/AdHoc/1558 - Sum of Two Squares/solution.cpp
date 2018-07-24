#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	bool res;
	while(cin >> n){
		res=false;
	 	for(int i=0; i*i<=n; i++){
			double aux=sqrt(n-i*i);
			if(aux==(int)aux){res=true;break;}
	 	}
	 	cout << ((res)? "YES\n" : "NO\n");
	}
   	return 0;
}