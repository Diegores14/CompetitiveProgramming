#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, c, aux;
	while(cin >> a >> c, a && c){
		long long ans = 0;
	 	for(int i=0; i < c; i++){
	 	 	cin >> aux;
	 	 	if(aux<a)
	 	 		ans += a-aux;
			a = aux;
	 	}
	 	cout << ans << '\n';	
	}
	return 0;
}