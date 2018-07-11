#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	n++;
	if(n==1){ cout << "0\n"; return 0;}
	if(n%2)cout << n <<'\n';
	else cout << n/2 << '\n';
 	return 0;
}