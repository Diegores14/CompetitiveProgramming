#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	bool salto=false;
	int n;
	while(cin >> n, n){
		if(salto)cout << '\n';
		else salto =true;
		bool res=false;
	 	for(int fghij=01234; fghij<=98765/n; fghij++){
	 	 	int abcde = fghij*n;
	 	 	int tmp, used= (fghij<10000);
	 	 	tmp= abcde; while(tmp){used |= (1<<tmp%10);tmp/=10;}
	 	 	tmp= fghij; while(tmp){used |= (1<<tmp%10);tmp/=10;}
	 	 	if(used == (1<<10)-1){
	 	 		printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
	 	 		res=true;	
	 	 	}
	 	}
	 	if(!res) cout << "There are no solutions for " << n << ".\n";
	}
        return 0;
}	