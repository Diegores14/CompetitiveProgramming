#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int x;
	cin >> x;
	if(x%2==0)x++;
	for(int i=0; i<6; i++){cout << x << '\n'; x+=2;}
	return 0;
}