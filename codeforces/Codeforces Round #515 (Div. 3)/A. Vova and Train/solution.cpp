#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, a, b, c, d;
	cin >> t;
	while(t--){
	 	cin >> a >> b >> c >> d;
		cout << (a/b)-((d/b)-((c-1)/b)) << '\n';
	}
	return 0;
}