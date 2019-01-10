#include <bits/stdc++.h>
using namespace std;
const int tam = 100000000;

int GCD(int a, int b){
 	return (b==0)? a : GCD(b, a%b); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<bool> criba(tam, true);
	criba[0]=criba[1]=false;
	for(int i=4; i<tam; i+=2){
	 	criba[i] =false;
	}
	for(int i=3; i*i<=tam; i+=2){
		if(criba[i])
		for(int j=i*i; j<tam; j+=i){
		 	criba[j]=false;
		}
	}
	int t, a, b;
	cin >> t;
	while(t--){
	 	cin >> a >> b;
		if(GCD(a,b)!=1)
			cout << "unknown\n";
		else{
		 	int i=0, cont=0;
			while(cont<10){
			 	int aux = a*i+b;
				if(criba[aux]){
					cont++;
					cout << aux << ((cont==10)? '\n' : ' ');
				}
				i++;
			}
		}
	}
	return 0;
}