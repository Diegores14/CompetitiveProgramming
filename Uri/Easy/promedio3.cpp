#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	float n1,n2,n3,n4,n5, prom;
	cin >>n1>>n2>>n3>>n4;
	prom = (n1*2+n2*3+n3*4+n4)/10;
	cout << setprecision(1) <<fixed<< "Media: " << prom <<'\n';
	if(prom>=7.0){cout<<"Aluno aprovado.\n";return 0;}
	if(prom<5.0){cout<<"Aluno reprovado.\n";return 0;}
	cout << "Aluno em exame.\n";
	cin >> n5;
	cout<< setprecision(1) <<fixed << "Nota do exame: " << n5 << '\n';
	prom = (prom+n5)/2;
	if(prom>=5.0){cout<<"Aluno aprovado.\n";}
	else cout<<"Aluno reprovado.\n";
	cout << setprecision(1) <<fixed<< "Media final: " << prom << '\n';
	return 0;
}