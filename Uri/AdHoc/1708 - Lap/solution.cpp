#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int x, y;
	double dif;
	while(cin >> x >> y){
	 	dif = y-x;
	 	cout << ceil(x/dif) + 1 << '\n';
	}
 	return 0;
}