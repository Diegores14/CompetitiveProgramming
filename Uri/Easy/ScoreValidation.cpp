#include <bits/stdc++.h>
using namespace std;

int main(){
	int i=0;
	double aux, v[2]; 
	while(i<2){
	 	cin >> aux;
		if(0<=aux && aux <= 10){v[i]=aux; i++;}
		else cout << "nota invalida\n"; 
	}	
	cout << setprecision(2) << fixed << "media = " << (v[0]+v[1])/2 << '\n';
	return 0;
}