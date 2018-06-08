#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y;
	cin >> x >> y;
	while(x>0 && y>0){
		int sum=0;
		if(x>y) swap(x,y);     
		for(int i=x; i<=y; i++){cout << i << ' '; sum += i;}
		cout << "Sum=" << sum << '\n';
	 	cin >> x >> y;
	}	
	return 0;
}