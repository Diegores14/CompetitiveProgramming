#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int x, y, a, b, h=0, m=0;
	cin >> x >> a >> y >> b; 
	if( a>b ) { m=b-a+60; h-=1;}
	if( b>a ) m=b-a;
                          
	if( x<y )  h+=y-x;
	if( x>y ) h+= y-x+24;
	if( x==y && a==b) h=24;
	cout << "O JOGO DUROU "<< h << " HORA(S) E "<< m <<" MINUTO(S)\n";
	return 0;
}