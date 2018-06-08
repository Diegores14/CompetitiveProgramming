#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double a,b,c,aux;
	cin>>a>>b>>c;
	if(a==0){cout<<"Impossivel calcular\n";return 0;}
	aux = b*b-4*a*c;
	if(aux<0){cout<<"Impossivel calcular\n";return 0;}
	cout <<setprecision(5)<<fixed<< "R1 = "<<(-b+sqrt(aux))/(2*a)<<'\n';
	cout <<setprecision(5)<<fixed<< "R2 = "<<(-b-sqrt(aux))/(2*a)<<'\n';
	return 0;
}