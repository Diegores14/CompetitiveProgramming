#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, aux;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++){cin >> aux; v[i]= (aux%2)? aux : aux-1;}
	for(int i=0; i<n; i++)cout << v[i] << ((i==n-1)? '\n' : ' ');
 	return 0;
}