#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r1, x1, y1, r2, x2, y2;
	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){
	 	double aux = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	 	if(aux+r2>r1) cout << "MORTO\n";
	 	else cout << "RICO\n";

	}
 	return 0;
}