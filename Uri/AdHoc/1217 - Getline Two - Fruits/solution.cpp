#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, amount=0, aux1;
	string s;
	double money=0,aux;
	cout << fixed << setprecision(2);
	cin >> n;
	for(int i=1; i<=n; i++){
	 	cout << "day " << i << ": ";
		cin >> aux;
		cin.ignore();
		getline(cin, s);
		aux1=1;
		for(int j=0; j<(int)s.size();j++)if(s[j]==' ')aux1++;
		cout << aux1 << " kg\n";
		money+=aux;
		amount+=aux1;
	}
	cout << (double)amount/n << " kg by day\n";
	cout << "R$ " << money/n << " by day\n";
 	return 0;
}