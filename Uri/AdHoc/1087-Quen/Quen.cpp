#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int x1,y1, x2,y2;
	while(cin >> x1 >> y1 >> x2 >> y2 && x1!=0 && y1!=0 && x2!=0 && y2!=0){
	 	if(x1==x2 && y1==y2){cout << "0\n";continue;}
		if(x1==x2 || y1==y2 || x1+y1==x2+y2 || x1-y1==x2-y2){ cout << "1\n";continue;}
		cout << "2\n";	
	}
	return 0;
}
