#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y;
	cin >> x >>y;
	for (int i=1; i<=y; i++){
		cout << i;
		if(i%x)cout << ' ';
		else cout << '\n';
	}
	return 0;
}