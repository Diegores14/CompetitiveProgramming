#include <bits/stdc++.h>
using namespace std;

int main (){
 	int n;
	cin >> n;
	int aux = n/2;
	for(int i =1; i<=aux; i++)if(n%i == 0)cout << i << '\n';
	cout << n << '\n';
	return 0;
}