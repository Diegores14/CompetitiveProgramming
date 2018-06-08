#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N;
	cin >> N;
	cout << N/365 << " ano(s)\n";
	N%=365;
	cout << N/30 << " mes(es)\n";
	N%=30;
	cout << N << " dia(s)\n";
}