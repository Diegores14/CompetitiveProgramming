#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, v[3] = {0,0,0};
	cin >> x;
	while(x!=4){
		if(0<x && x<4)v[x-1]++;
		cin >> x;
	}
	cout << "MUITO OBRIGADO\n";
	cout << "Alcool: " << v[0] << '\n';
	cout << "Gasolina: " << v[1] << '\n';
	cout << "Diesel: " << v[2] << '\n';
}