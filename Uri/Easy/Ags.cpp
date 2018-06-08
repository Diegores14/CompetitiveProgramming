#include <bits/stdc++.h>
using namespace std;

int main(){
 	int x, cont=0, sum=0;
	cin >> x;
	while(0<x){ sum += x; cont++; cin >> x;}
	cout << setprecision(2) <<fixed<< double(sum)/cont << '\n';
	return 0;
}