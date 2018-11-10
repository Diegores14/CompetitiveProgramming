#include <bits/stdc++.h>
using namespace std;

bool tipo(string s){
	if(s[0]!='R' || ('A'<=s[1] && s[1]<='Z'))return true;
	for(int i=2; i<(int)s.size(); i++)if(s[i]=='C')return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	while(n--){
	 	cin >> s;
		if(tipo(s)){
		 	cout << 'R';
			int aux=0;
			int i;
			for(i=0; 'A'<=s[i] && s[i]<='Z'; i++)aux = aux*26 + s[i]-'A'+1;
			for(; i <(int)s.size(); i++)cout << s[i];
			cout << 'C' << aux << '\n';
			
		}else{
			bool col=false;
			int x=0;
			for(int i=1; i<(int)s.size(); i++){
			 	if(col)x =  x*10 + s[i]-'0';
				if(s[i]=='C') col = true;
			}
			string aux;
			while(x){
				if(x%26){
					aux.push_back(x%26+'A'-1);
					x/=26;
				}
				else{
					aux.push_back('Z');
					x=x/26-1;
				}
			}
			for(int i=(int)aux.size()-1; i>=0; i--) cout << aux[i];
			for(int i=1; s[i]!='C'; i++) cout << s[i];
			cout << '\n';
		}
	}
	return 0;
}