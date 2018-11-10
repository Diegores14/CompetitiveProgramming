#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, m;
	cin >> n >> m;
	if((n-2*m)<=0)
		cout << "0 ";
	else{
	 	cout << (n-2*m) << ' ';
	}
	if(m==0){
	 	cout << n << '\n';
	}else{
		cout << n-ceil((1+sqrt(1+8*m))/2) << '\n';
	}
	return 0;
}