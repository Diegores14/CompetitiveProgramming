#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k){
	if(n==1) return 1;
	return (josephus(n-1,k)+k-1)%n+1; 	    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int res, n;
	cin >> n;
	while(n){
		int i=1;
		while(josephus(n-1, i)!=12)i++;
		cout << i << '\n';
		cin >> n;
	}
	return 0; 
}