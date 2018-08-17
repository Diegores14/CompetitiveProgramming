#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, c, v, ans;
	while(cin >> n, n){
		ans = 0;
	 	while(n--){ cin >> c >> v; ans += v/2;}
	 	cout << ans/2 << '\n';
	}
	return 0;
}