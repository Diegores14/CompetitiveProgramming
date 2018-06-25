#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s; 
	while(getline(cin, s)){
	 	for(int i=0; i<(int)s.size(); i++){
		 	if('a'<=s[i] && s[i]<='z'){
				if('z' < s[i]+13){cout << (char)('a'+(s[i]-'z')+12);}
				else cout << (char)(s[i]+13);
				continue;
			}
			if('A'<=s[i] && s[i]<='Z'){
				if('Z' < s[i]+13){cout << (char)('A'+(s[i]-'Z')+12);}
				else cout << (char)(s[i]+13);
				continue;
			}
			cout << s[i];
		}
		cout << '\n';
	}
 	return 0;
}