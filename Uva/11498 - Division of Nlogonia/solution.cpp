#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x, y, cx, cy;
	while(cin >> n, n){
	 	cin >> cx >> cy;
		for(int i=0; i<n; i++){
		 	cin >> x >> y;
			if(x == cx || y == cy)cout << "divisa\n";
			else{
			 	if((y-cy)>0)cout << "N";
				else cout << "S";
				if((x-cx)>0)cout << "E\n";
				else cout << "O\n";
			}
		}
	}
	return 0;
}