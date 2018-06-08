#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int cont=0;
	double aux, sum=0;
	for(int i=0; i<6; i++){cin>>aux; if(aux>0){cont++; sum+=aux;}}
	cout << setprecision(1) <<fixed << cont << " valores positivos\n" << sum/cont << '\n';
	
}