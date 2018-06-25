#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, x, y;
	while(cin >> t, t){
		int cont1=0,cont2=0;
		while(t--){
	 		cin >> x >> y;
			if(x==y)continue;
			if(x>y)cont1++;
			else cont2++;
		}
		cout << cont1 << ' ' << cont2 << '\n';
	}
	return 0;
}