#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
 	return b? gcd(b, a%b) : a;
}

long long lcm(int a, int b, int c){

 	return (long long)(a/c) * b;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;
	cin >> n;
	while(n--){
	 	cin >> a >> b;
		int c = gcd(a,b);
		cout << c << ' ' << lcm(a,b,c) << '\n';
	}
 	return 0;
}
