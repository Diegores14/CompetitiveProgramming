#include <bits/stdc++.h>
using namespace std;

int main(){
 	int x, y, sum=0, cont=0;
	cin >> x >> y;
	while(y<=x)cin >> y;
	while(sum<=y){
	 	sum+=x;
		x++;cont++;
	}
	cout << cont << '\n';
}