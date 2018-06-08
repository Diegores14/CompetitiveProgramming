#include <bits/stdc++.h>
using namespace std;


int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int aux, mayor=0, posicion=0;
	for(int i=1; i<=100;i++){ cin >> aux; if(aux>mayor){ mayor = aux; posicion = i;}}
	cout << mayor << '\n' << posicion << '\n';
	return 0; 
}