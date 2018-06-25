#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	char n;
	string s;
	while(cin >> n >> s, n!='0' || s!="0"){
		bool res=false;
		for(int i=0; i<(int)s.size(); i++){
			if(s[i]!=n && s[i]!='0')res=true;
			if(s[i]==n){s.erase(i,1);i=-1;}
			if(i==0 && s[i]=='0'){s.erase(i,1);i=-1;}
		}
		cout << ((res)? s : "0") << '\n';

	}
	return 0;
}