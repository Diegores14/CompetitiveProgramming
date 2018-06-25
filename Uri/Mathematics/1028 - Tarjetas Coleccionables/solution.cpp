#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){  
	return ((!b)? a : GCD(b,a%b));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;
	cin >> n;
	while(n--){
	 	cin >> a >> b;
		if(a<b)swap(a,b);
		cout << GCD(a,b) << '\n';
	}
	return 0;
}