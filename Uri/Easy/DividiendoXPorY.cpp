#include <bits/stdc++.h>
using namespace std;

int main (){
	int N, x, y;
	cin >> N;
	cout << setprecision(1) << fixed;
	while(N--){
	 	cin >> x >> y;
		if(y!=0) cout << double(x)/y << '\n';
		else cout << "divisao impossivel\n";
	}
	return 0;
} 	