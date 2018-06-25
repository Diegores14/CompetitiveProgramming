#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,x,y,i=0;
	vector<string> v(3);
	v[0]="Rafael ganhou";
	v[1]="Beto ganhou";
	v[2]="Carlos ganhou";
	cin >> n;
	while(n--){
	 	cin >> x >> y;
		if((9*x*x+y*y)>(2*x*x+25*y*y))i=0;
		else i=1;
		if(max((9*x*x+y*y),(2*x*x+25*y*y))<(-100*x+y*y*y))i=2;
		cout << v[i] << '\n';
	}
	return 0;
}