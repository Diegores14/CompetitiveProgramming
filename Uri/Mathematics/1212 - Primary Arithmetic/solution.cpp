#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long a, b;
	int cont, aux;
	while(cin >> a >> b, a || b){
	 	cont=0;
		aux=0;
		while((a&&b) || aux){
		 	aux=(a%10+b%10+aux)/10;
			if(aux)cont++;
			a/=10;
			b/=10;
		}
		if(cont) cout << cont << " carry operation" << ((cont==1)? ".\n" : "s.\n");
		else cout << "No carry operation.\n";
	}
 	return 0;
}