#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, mx;
	while(cin >> n, n){
	 	mx=n;
	 	while(n!=1){
	 	 	if(n%2)n=3*n+1;
	 	 	else n>>=1;
	 	 	if(n>mx)mx=n;
	 	}
	 	cout << mx << '\n';
	}
 	return 0;
}