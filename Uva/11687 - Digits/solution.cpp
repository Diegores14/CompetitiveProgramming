#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	while(cin >> s, s != "END"){
	 	if(s=="1")
	 		cout << "1\n";
	 	else{
			int aux = s.size(), i = 1;
			while(aux != 1){
			 	i++;
			 	int tam = 0;
			 	while(aux){
			 	 	tam++;
			 	 	aux/=10;
			 	}
			 	aux = tam;
			}
			cout << i+1 << '\n';
	 	}
	}
	return 0;
}