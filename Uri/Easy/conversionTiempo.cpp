#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N;
	cin >> N;
	cout << N/3600 << ':';
	N%=3600;
	cout << N/60 << ':';
	N%=60;
	cout << N << '\n';
	return 0;
}