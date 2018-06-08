#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);	
 	int cont =0;
	double aux;
	for (int i =0; i<6; i++) {cin>>aux;if(aux>0)cont++;}
	cout << cont << " valores positivos\n";
	return 0;
}