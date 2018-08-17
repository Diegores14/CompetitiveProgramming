#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b;
	string s;
	while(cin >> s){
		vector<int> v(11);
		a=b=0;
		int j=0;
		for(int i=0; i<(int)s.size(); i++) if(s[i]!='.' && s[i]!='-') v[j++]=s[i]-'0';
		for(int i=0; i<9; i++){a+=v[i]*(i+1); b+=v[8-i]*(i+1);}
		bool answer = true;
		if(a%11==10){ if(0!=v[9])answer=false;}
		else if(a%11!=v[9]) answer=false;
		if(b%11==10){ if(0!=v[10])answer=false;}
		else if(b%11!=v[10]) answer=false;
		if(answer) cout << "CPF valido\n";
		else cout << "CPF invalido\n";
	}
 	return 0;
}