#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, ans;
	double cuotaInicial, loan;
	while(cin >> n >> cuotaInicial >> loan >> m, n>0){
		vector<pair<int,double>> depresation(m);
		for(int i=0; i<m; i++){
		 	cin >> depresation[i].first >> depresation[i].second;
		}
		ans = 0;
		int l=1;
		double owes = loan, aux = loan/n, valueCar = (loan+cuotaInicial)*(1-depresation[0].second);
	        while(owes >= valueCar){
			ans++;
	         	if(l<m && depresation[l].first == ans)
				l++;
			owes -= aux;
			valueCar *= (1 - depresation[l-1].second);
		}
	 	cout << ans << " month" << ((ans!=1)? "s\n" : "\n");
	}
	return 0;
}