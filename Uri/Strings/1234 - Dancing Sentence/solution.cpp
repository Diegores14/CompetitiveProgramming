#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	string s;
	while(getline(cin,s)){
		int k=0;
	 	for(int i=0; i<(int)s.size(); i++){
			if('a'<=s[i] && s[i]<='z' && k%2==0)s[i]-=32;
			if('A'<=s[i] && s[i]<='Z' && k%2)s[i]+=32;
			if(s[i]!=' '){k++;}
			cout << s[i];  
		}
		cout << '\n';
	}
	return 0;
}