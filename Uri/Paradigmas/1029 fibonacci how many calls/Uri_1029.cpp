#include <bits/stdc++.h>
using namespace std;
vector<long long> fibo(40,-1);
vector<long long> calls(40,0);
long long fibonacci(int n){
	if(fibo[n]==-1){fibo[n]=fibonacci(n-1) + fibonacci(n-2);
	calls[n] = calls[n-1]+calls[n-2]+2;}
	return fibo[n];
}

int main(){
	calls[0]=calls[1]=0;
	fibo[0]=0;fibo[1]=1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,x;
	cin >> N;
	while(N--){
	 	cin >> x;
	 	cout << "fib(" << x << ") = " << calls[x] << " calls = " << fibonacci(x) << '\n';
	}
 	return 0;
}