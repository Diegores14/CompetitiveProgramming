#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s, ans=0;
	cin >> n >> s;
	for(int i=n; i>0; i--){
		if(s/i){
			ans += s/i;
			s = s%i;
		}
	}
	cout << ans << '\n';
	return 0;
}