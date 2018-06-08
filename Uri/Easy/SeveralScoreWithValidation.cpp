#include <bits/stdc++.h>
using namespace std;

int main(){
	int x=1, cont=0; 
	double a, sum=0;
	cout << setprecision(2) << fixed;
	while(x!=2){    
	 	cin >> a;
		if(0<=a && a<=10){sum+=a; cont++;}
		else cout << "nota invalida\n";
		if(cont == 2) cout << "media = " << sum/2 << '\n';
		while(cont == 2){
		 	cout << "novo calculo (1-sim 2-nao)\n";
			cin >> x;
			if(x==2) return 0;
			if(x==1){cont = 0; sum = 0;}
		}
	}	
	return 0;
}