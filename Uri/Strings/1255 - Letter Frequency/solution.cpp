#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n;
	cin >> n;
	string s;
	cin.ignore();
	while(n--){
		getline(cin, s);
		vector<int> v(26,0);
		for(int i=0; i<(int)s.size(); i++){
		 	if('A'<=s[i]&&s[i]<='Z')s[i]+=32;
			if('a'<=s[i]&&s[i]<='z')v[s[i]-'a']++;
		}
		int maximo=0;
		for(int i=0; i<26; i++){
		 	maximo = max(v[i],maximo);
		}
		for(int i=0; i<26; i++)if(maximo == v[i])cout << (char)(i+'a');
		cout << '\n';
	}
	return 0;
}