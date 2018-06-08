#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int a,b, t;
	float g1, g2;
	cin >>t;
	while(t--){
		cin >> a >> b >> g1 >> g2;
		int cont=0;
		while(a<=b && cont <= 100){
		 	a+=int(a*g1/100);
			b+=int(b*g2/100);
			cont++;
		}
		if(cont<=100)cout << cont << " anos.\n";
		else cout << "Mais de 1 seculo.\n";
	}
	return 0;
}