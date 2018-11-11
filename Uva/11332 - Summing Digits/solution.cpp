#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	unsigned int n;
	while(cin >> n, n){
		while(n>=10){
			unsigned int aux = 0;
			while(n){
			 	aux += n%10;
				n /= 10;
			}
			n = aux;
		}
		cout << n << '\n';
	}
	return 0;
}