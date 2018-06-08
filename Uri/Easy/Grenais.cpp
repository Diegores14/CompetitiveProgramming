#include <bits/stdc++.h>
using namespace std;

int main() {
	int x=1, a, b, cont1=0, cont2=0, emp=0;
	while(x!=2){
		cin >> a >>b;
		if(a>b)cont1++;
		if(a<b)cont2++;
		if(a==b)emp++;
		cout << "Novo grenal (1-sim 2-nao)\n";
		cin >> x;
		while(x!=1 && x!=2){
	        	cout << "Novo grenal (1-sim 2-nao)\n";
			cin >> x; 	
		}
	}	
	cout << cont1 + cont2 + emp << " grenais\n";
 	cout << "Inter:" << cont1 << '\n';
	cout << "Gremio:" << cont2 << '\n';
	cout << "Empates:" << emp << '\n';
	if(cont1==cont2) cout << "Não houve vencedor\n";
	else cout <<((cont1>cont2)? "Inter " : "Gremio " ) << "venceu mais\n";
}