#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, a, b, p, c;
	cin >> t;
	for(int k=1; k<=t; k++){
		cout << "Case #" << k << ": ";
		if(k!=1){
		 	cin.ignore();
			cin.ignore();
		}
		cin >> n;
		vector<int> city(5001, 0);
		for(int i=0; i<n; i++){
		 	cin >> a >> b;
			for(int j=a; j<=b; j++){
			 	city[j]++;
			}
		}
		cin >> p;
		for(int i=0; i<p; i++){
		 	cin >> c;
			cout << city[c] << ((i==p-1)? '\n' : ' ');
		}
	}
	return 0;
}