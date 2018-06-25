#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	string s, aux;
	cin >> s;
	for(int i=0; i<(int)s.size(); i++){
	 	if('a'==s[i])aux.push_back(s[i]);
		if('e'==s[i])aux.push_back(s[i]);
		if('i'==s[i])aux.push_back(s[i]);
		if('o'==s[i])aux.push_back(s[i]);
		if('u'==s[i])aux.push_back(s[i]);
	}
	bool res=true;
	int n=aux.size()/2;
	for(int i=0; i<n; i++){
	 	if(aux[i]!=aux[aux.size()-i-1]){res=false; break;}
	}                 
	cout << ((res)? "S\n" : "N\n");
	return 0;
}