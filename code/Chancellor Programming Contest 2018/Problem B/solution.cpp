#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<char> v({'G','B','R'});
	long long n;
	while(cin >> n){
	 	n--;
		stack<char> pila;
		while(n>0){
			n--;
			pila.push(v[n%3]);
			n/=3;
		}
		while(!pila.empty()){
		        cout << pila.top();
			pila.pop();
		}	
		cout << "S\n";
	}
	return 0;
}