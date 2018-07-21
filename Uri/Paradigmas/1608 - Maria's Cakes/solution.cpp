#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, d, i, b, index, amount, sum, mx, aux;
	cin >> t;
	while(t--){
		mx = 0;
	 	cin >> d >> i >> b;
	 	vector<int> v(i);
	 	for(int j=0; j<i; j++)cin >> v[j];
		for(int j=0; j<b; j++){
			sum = 0;
		 	cin >> aux;
		 	for(int k=0; k<aux; k++){
		 		cin >> index >> amount; sum+=v[index]*amount;
		 	}
		 	mx = max(mx, d/sum);
		}
		cout << mx << '\n';
	}
 	return 0;
}