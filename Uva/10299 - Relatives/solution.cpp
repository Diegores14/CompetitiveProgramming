#include <bits/stdc++.h>
using namespace std;

int totient(int n){
	int result = n;
	if(n==1)return 0;
	for(int i=2; i*i<=n; i++){
	 	if(n%i==0){
	 	 	while(n%i==0)n/=i;
			result -= result/i;
		} 
	}
	if(n>1)result-=result/n;
        return result;
}	

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n, n){
		cout << totient(n) << '\n';
	}
 	return 0;
}