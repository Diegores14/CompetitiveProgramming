#include <bits/stdc++.h>
using namespace std;
vector<long long> fibo(61,0);
long long fibonacci(long long x){
 	if(x==0)return fibo[0];
	if(x==1)return fibo[1];
	if(fibo[x]!=0) return fibo[x];
	return fibo[x]= fibonacci(x-1)+fibonacci(x-2);
}

int main(){
	fibo[1]=1;
 	long long N, x;
	cin >> N;
	while(N--){
	 	cin >> x;
		cout << "Fib(" << x << ") = " << fibonacci(x) << '\n';
	}
	return 0;
}
