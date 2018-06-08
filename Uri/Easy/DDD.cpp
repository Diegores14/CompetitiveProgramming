#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	map<int,string> m;
	int n;
	cin >> n;
	m[61]="Brasilia\n";
	m[71]="Salvador\n";
	m[11]="Sao Paulo\n";
	m[21]="Rio de Janeiro\n";
	m[32]="Juiz de Fora\n";
	m[19]="Campinas\n";
	m[27]="Vitoria\n";
	m[31]="Belo Horizonte\n";
	if(m.find(n)!= m.end())cout << m[n];
	else cout <<"DDD nao cadastrado\n";
	return 0;
}