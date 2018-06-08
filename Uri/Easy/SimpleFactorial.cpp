#include <bits/stdc++.h>
using namespace std;

int main(){
	long long N, res;
 	cin >> N;
	res=N;
	while(--N)res*=N;
	cout << res << '\n';
	return 0;
}