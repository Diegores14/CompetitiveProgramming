#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int  f, m, i=1;
	string s, n;
	while(cin >> n){
		f=m=0;
		if(i!=1) cout << '\n'; 
		cout << "Caso " <<i <<":\n";
		i++;
		cin.ignore();
		getline(cin, s);
		for(int j=0; j<(int)s.size(); j+=5){
		 	if(n == s.substr(j, 2)){
		 	 	if(s[j+3]=='F')f++;
		 	 	else m++;
		 	}
		}
		cout << "Pares Iguais: " << m+f << '\n';
		cout << "F: " << f << '\n';
		cout << "M: " << m << "\n";
	}
 	return 0;
}