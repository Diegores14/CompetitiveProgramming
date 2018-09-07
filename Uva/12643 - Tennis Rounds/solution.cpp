#include <bits/stdc++.h>
using namespace std;

int division(int n){
 	return (n&1)? (n>>1)+1 : (n>>1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, i, j;
	while(cin >> n >> i >> j){
		int k=0;
		for(; i!=j; k++){
		 	i=division(i);
			j=division(j);
		}
		cout << k << '\n';
	}
	return 0;
}