#include <bits/stdc++.h>
using namespace std;

int main(){
 	int N, a=0, b=1, aux;
	cin >> N;
	if(0<N){cout << a; N--;}
	if(0<N){cout << ' ' << b; N--;}
	while(N--){cout << ' ' << a+b;aux=a; a=b; b=aux+b;}
	cout << '\n';
	return 0;
}