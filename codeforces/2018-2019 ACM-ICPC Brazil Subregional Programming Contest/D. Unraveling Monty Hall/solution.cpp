#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, aux, ans=0;
	cin >> n;
	while(n--){
	 	cin >> aux;
		if(aux!=1)ans++;
	}
	cout << ans << '\n';
	return 0;
}