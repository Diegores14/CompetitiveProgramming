#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int ans=0, aux;
	while(cin >> aux, aux)ans = max(ans, aux);
	cout << ans << '\n';
	return 0;
}