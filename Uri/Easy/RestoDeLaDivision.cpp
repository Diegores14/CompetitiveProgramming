#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	if(x>y)swap(x,y);
	for(int i=x+1; i < y; i++)if(i%5==2 || i%5==3) cout << i <<'\n';
	return 0; 
}