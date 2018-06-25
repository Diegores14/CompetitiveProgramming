#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	map<char,double> m;
	m['W']=1;
	m['H']=(double)1/2;
	m['Q']=(double)1/4;
	m['E']=(double)1/8;
	m['S']=(double)1/16;
	m['T']=(double)1/32;
	m['X']=(double)1/64;
	while(getline(cin,s) && s!="*"){
		int res=0;
		double cont=0;
	 	for(int i=1; i<(int)s.size();i++){
		 	if(s[i]=='/'){
				if(cont==1)res++;
				cont=0;
			}else cont+=m[s[i]];
		}
		cout << res << '\n';
	}
 	return 0;
}