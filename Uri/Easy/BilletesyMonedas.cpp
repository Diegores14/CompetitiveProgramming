#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	double n;
	int a, m,aux;
	
	cin >> n;
	a = (int)n;
	aux = n*100;
	m=aux-a*100;
	cout << "NOTAS:\n";
	cout << (int)a/100 << " nota(s) de R$ 100.00\n";
		a%=100;
	cout << (int)a/50 << " nota(s) de R$ 50.00\n";
		a%=50;
	cout << (int)a/20 << " nota(s) de R$ 20.00\n";
		a%=20;
	cout << (int)a/10 << " nota(s) de R$ 10.00\n";
		a%=10;
	cout << (int)a/5 << " nota(s) de R$ 5.00\n";
		a%=5;
	cout << (int)a/2 << " nota(s) de R$ 2.00\n";
		a%=2;
	cout << "MOEDAS:\n";	
	cout << (int)a/1 << " moeda(s) de R$ 1.00\n";
		a%=1;	
	cout << (int)m/50 << " moeda(s) de R$ 0.50\n";
		m %=50;
	cout << (int)m/25 << " moeda(s) de R$ 0.25\n";
		m%=25;
	cout << (int)m/10 << " moeda(s) de R$ 0.10\n";
		m %= 10;
	cout << (int)m/5 << " moeda(s) de R$ 0.05\n";
		m%=5;
	cout << m/1.0 << " moeda(s) de R$ 0.01\n";
return 0;
}