#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k){
	if(n==1) return 1;
	return (josephus(n-1,k)+k-1)%n+1; 	    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nc, n , k;
	cin >> nc;
	for(int i = 1; i <= nc; i++){
	 	cin >> n >> k;    
		cout << "Case " << i << ": " << josephus(n,k) << '\n';
	}
	return 0; 
}