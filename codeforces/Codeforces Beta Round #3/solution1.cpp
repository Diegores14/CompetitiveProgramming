#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s1, s2;
	int x, y;
	cin >> s1 >> s2;
	x = s2[0]-s1[0];
	y = s2[1]-s1[1];
	cout << max(abs(x), abs(y)) << '\n';
	char c1 = ((x<0)? 'L' : 'R');
	char c2 = ((y<0)? 'D' : 'U');
	x=abs(x);
	y=abs(y);
	if(x>y){
	 	while(x!=y){
	 	 	cout << c1 << '\n';
			x--;
		}
	}
	if(y>x){
	 	while(x!=y){
	 	 	cout << c2 << '\n';
			y--;
		}
	}         
	while(x!=0){
	 	cout << c1 << c2 << '\n';
		x--;
	}
	return 0;
}