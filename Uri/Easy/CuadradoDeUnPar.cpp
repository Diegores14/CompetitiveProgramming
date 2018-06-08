#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for ( int i =2; i<=N; i+=2)cout << i << "^2" << " = " << i*i << '\n';
	return 0; 
}