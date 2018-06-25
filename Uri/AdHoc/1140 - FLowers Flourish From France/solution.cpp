#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 	string s;
	while(true){
	 	getline(cin, s);
		if(s=="*")break;
		char c = ('A' <= s[0] && s[0] <= 'Z')? s[0]+32 : s[0];
		bool res=true, sal=false; 
		for(int i=1; i<(int)s.size(); i++){
			if(sal){
				if('A' <= s[i] && s[i] <= 'Z') s[i]+=32;
				//cout << s[i];
				if(s[i]!=c){
					res=false;
					break;
				}
				sal=false;
			}
			if(s[i]==' ')sal=true;
		}
		cout << ((res)? "Y\n" : "N\n"); 
	}
	return 0;

}