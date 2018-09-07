#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, t;
	double b, c;
	cout << fixed << setprecision(2);
	while(cin >> t, t){
		for(int i=1; i<=t; i++){
		 	cout << "Size #" << i << ":\n";
		 	cin >> a >> b >> c;
		 	cout << "Ice Cream Used: " << a*(5*(b+c)/2) << " cm2\n";
		}
		cout << '\n';
	}
	return 0;
}