#include <bits/stdc++.h>
using namespace std;

int main(){
	double i=0, j=1, aux=0;
	while(i<2){
		cout << "I=" << i << " J=" << j+i << '\n';
		aux++;
		j++;
		if(fmod(aux,3)==0){aux=0;}
		if(aux == 0){j=1; i+=0.2;}
	}	return 0;
}