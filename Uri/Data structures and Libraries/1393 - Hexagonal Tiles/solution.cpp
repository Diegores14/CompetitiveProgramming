#include <bits/stdc++.h>
using namespace std;
vector<long long> fibo(42,0);

long long fibonacci(int n){
        if(fibo[n]!=0)return fibo[n];
	return fibo[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	fibo[1]=1;
	fibo[2]=2;
	while(cin >> n, n){
	 	cout << fibonacci(n) << '\n';
	}
 	return 0;
}