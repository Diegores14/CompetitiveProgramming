#include <bits/stdc++.h>
using namespace std;


int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, sum=0;
	cin >> x >> y;
	if(x > y) swap(x,y);
	for (int i=x+1; i<y; i++){
	 	if(i%2) sum+=i;
	}
	cout << sum << '\n';
	return 0;
}