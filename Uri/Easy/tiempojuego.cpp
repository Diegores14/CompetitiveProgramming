#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int x, y, res;
	cin >> x >> y;
	if( x==y ) res=24;
	if( x<y )  res=y-x;
	if( x>y ) res= y-x+24;
	cout << "O JOGO DUROU "<< res << " HORA(S)\n";
	return 0;
}