#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int pos, a, b, c;
	while( cin >> pos >> a >> b >> c, pos || a || b || c){
		int ans = 1080;
		if(a < pos)ans += (pos - a)*9;
		else ans += (pos - a + 40)*9;
		if(a < b)ans += (b - a)*9;
		else ans += (b - a + 40)*9;
		if(c < b) ans += (b - c)*9;
		else ans += (b - c + 40)*9;
		cout << ans << '\n';
	}
	return 0;
}