#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n, n){
	 	char c;
	 	long long ans = 1000000000000000;
	 	long long drugs = 1000000000000000, restaurant = 1000000000000000;
	 	for(int i=0; i<n; i++){
	 	 	cin >> c;
	 	 		if(c == 'R'){
	 	 		 	restaurant = i;
					ans = min(ans, abs(drugs-restaurant));
	 	 		}
	 	 		if(c == 'D'){
	 	 		 	drugs = i;
					ans = min(ans, abs(drugs-restaurant));
	 	 		}
	 	 		if(c == 'Z')
	 	 			ans = 0;
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}