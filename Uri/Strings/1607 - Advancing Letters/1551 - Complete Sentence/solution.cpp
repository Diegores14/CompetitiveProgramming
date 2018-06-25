#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,aux;
	string s;
	vector<int> v;
	cin >> n;
	cin.ignore();
	while(n--){
		aux=0;
		v.assign(26,0);
	 	getline(cin, s);
		for(int i=0; i<(int)s.size();i++){
		 	if('A'<= s[i] && s[i]<='Z')s[i]+=32;
			v[s[i]-'a']=1;
		}
		for(int i=0; i<26; i++)aux+=v[i];
		if(aux==26){cout << "frase completa\n";continue;}
		if(aux>=13){cout << "frase quase completa\n";continue;}
		cout << "frase mal elaborada\n";
	}
 	return 0;
}