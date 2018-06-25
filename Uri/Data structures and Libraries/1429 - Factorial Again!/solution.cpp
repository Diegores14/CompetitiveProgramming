#include <bits/stdc++.h>
using namespace std;
vector<int> fac(10,0);

int factorial(int n){
 	if(fac[n]!=0)return fac[n];
	return fac[n]=factorial(n-1)*n;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	long long sum;
	fac[0]=fac[1]=1;
	while(cin >> n, n){
		int i=1;
		sum=0;
	 	while(n){
	 	 	sum+=(n%10)*factorial(i++);
			n/=10;
		}
		cout << sum << '\n';
	}
 	return 0;
}