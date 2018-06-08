#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	double a;
	cin >> a;
	if(0<=a && a<=25){cout<<"Intervalo [0,25]\n";return 0;}
	if(25<a && a<=50){cout<<"Intervalo (25,50]\n";return 0;}
	if(50<a && a<=75){cout<<"Intervalo (50,75]\n";return 0;}
	if(75<a && a<=100){cout<<"Intervalo (75,100]\n";return 0;}
	cout << "Fora de intervalo\n";
	return 0;
}