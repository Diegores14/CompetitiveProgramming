#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, cont=0;
	double m;
	cin >> n;
	while(n--){
	 	cin >> m;
		cont = 0;
		while(1<m){
		 	cont++;
			m/=2;
		}
		cout << cont << " dias\n";
	}
 	return 0;
}