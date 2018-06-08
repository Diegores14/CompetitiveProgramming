#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	bool res = true;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(!(b>c))res=false;
	if(!(d>a))res=false;
	if(!((a+b)<(c+d))) res = false;
	if(a%2) res = false;
	cout << ((res)? "Valores aceitos\n" : "Valores nao aceitos\n");
	return 0;
}