#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n, x, y, x1,y1;
	while(cin >> n, n){
	 	cin >> x >> y;
		while(n--){
		 	cin >> x1 >> y1;
			if(x== x1 || y == y1){ cout << "divisa\n"; continue;}
			if(y1 > y)cout << "N";
			else cout << "S";
			if(x1 > x)cout << "E\n";
			else cout << "O\n";
		}
	}
	return 0;
}