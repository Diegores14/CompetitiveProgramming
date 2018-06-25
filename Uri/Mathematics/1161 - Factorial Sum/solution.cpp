#include <bits/stdc++.h>
using namespace std;
vector<unsigned long long> fac(21,0);

unsigned long long factorial(unsigned long long n){
 	if(fac[n]!=0)return fac[n];
	return fac[n]= (factorial(n-1)*n);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;
	fac[0]=1;
	while(cin >> n >> m){
	 	cout << (factorial(n)+factorial(m)) << '\n';
	}
 	return 0;
}