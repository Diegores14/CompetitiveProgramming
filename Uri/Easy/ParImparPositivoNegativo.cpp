#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int aux,par=0,positivos=0, negativos=0;
	for(int i=0; i<5;i++){
	 	cin >> aux;
		if(aux%2==0)par++;
		if(aux>0) positivos++;
		if(aux<0) negativos++;
	}
	cout << par << " valor(es) par(es)\n";
	cout << 5-par << " valor(es) impar(es)\n";
	cout << positivos << " valor(es) positivo(s)\n";
	cout << negativos << " valor(es) negativo(s)\n";
	return 0; 
}