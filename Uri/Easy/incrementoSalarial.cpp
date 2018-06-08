#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	int v[5] = {15, 12, 10, 7, 4};
	double n;
	cin >> n;
	if(0<=n && n<=400.00) i=0;
	if(400.01<=n && n<=800.00) i=1;
	if(800.01<=n && n<=1200.00) i=2;
	if(1200.01<=n && n<=2000.00) i=3;
	if(2000<n) i=4;
	cout << setprecision(2) << fixed << "Novo salario: " << n+n*(v[i]/100.0) << '\n';
	cout << setprecision(2) << fixed << "Reajuste ganho: " << n*(v[i]/100.0) << '\n';
	cout << "Em percentual: " << v[i] << " %\n";
	return 0;
}