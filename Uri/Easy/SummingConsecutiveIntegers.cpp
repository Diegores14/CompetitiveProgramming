#include <bits/stdc++.h>
using namespace std;

int main(){
 	int x,y, res=0;
	cin >> x >> y;
	while(y<=0)cin >>y;
	while(y--){
	 	res+=x;
		x++;
	}
	cout << res << '\n';
}