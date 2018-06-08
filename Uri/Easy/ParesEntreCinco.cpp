#include <bits/stdc++.h>
using namespace std;


int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int aux;
	int cont=0;
	for(int i=0; i<5; i++){cin >> aux; if(aux%2==0) cont++;}
	cout << cont << " valores pares\n";
	return 0;
}