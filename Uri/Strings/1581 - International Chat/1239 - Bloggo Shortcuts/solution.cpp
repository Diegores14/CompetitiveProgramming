#include <bits/stdc++.h>
using namespace std;

int main(){
 	string s;
	while(getline(cin, s)){
		bool a=true, b=true;
		for(int i=0; i<(int)s.size(); i++){
			if(a && s[i]=='_'){cout << "<i>";a=false;continue;}
			if(!a && s[i]=='_'){cout << "</i>";a=true;continue;}
			if(b && s[i]=='*'){cout << "<b>";b=false;continue;}
			if(!b && s[i]=='*'){cout << "</b>";b=true;continue;}
			cout << s[i];
		}	
		cout << '\n';
	}
	return 0;
}