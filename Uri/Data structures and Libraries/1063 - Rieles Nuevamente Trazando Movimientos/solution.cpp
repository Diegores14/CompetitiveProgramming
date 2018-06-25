#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){
	 	stack<char> pila;
		vector<char> v(n);
		vector<char> v1(n);
		for(int i=0; i<n; i++)cin >> v[i];
		for(int i=0; i<n; i++)cin >> v1[i];
		int j=0;
		for(int i=0; i<n; i++){
			cout << 'I';
			pila.push(v[i]);
			while(!pila.empty() && pila.top()==v1[j]){
				cout << 'R';
				pila.pop();
				j++;
			}
		}
		if(!pila.empty())cout << " Impossible";
		cout << '\n';
	}
	return 0;
}