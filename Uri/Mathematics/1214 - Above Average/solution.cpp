#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, cont, sum;
	double prom;
	cin >> t;
	cout << setprecision(3) << fixed;
	while(t--){
	 	cin >> n;
		cont=0; sum=0;
		vector<int> v(n);
		for(int i=0; i<n; i++){cin >> v[i];sum+=v[i];}
		prom=(double)sum/n;
		for(int to : v)if(to>prom)cont++;
		cout << (double)100*cont/n << "%\n";
	}
	return 0;
}