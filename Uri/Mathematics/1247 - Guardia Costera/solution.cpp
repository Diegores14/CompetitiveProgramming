#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, c;
	while(cin >> a >> b >> c){
		if(b>=c){cout << "N\n"; continue;}
	 	double t=(double)a/sqrt(c*c-b*b);
		if(t*b>12)cout << "N\n";
		else cout << "S\n";
	}
	return 0;
}