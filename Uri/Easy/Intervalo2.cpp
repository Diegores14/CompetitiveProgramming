#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int x, cont =0, aux ;
	cin >> x;
	for(int i =0; i<x; i++){
	 	cin >> aux;
		if(10<=aux && aux <=20)cont++;
	}
	cout << cont << " in\n" << x-cont << " out\n";
	return 0;
}