#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	while(getline(cin, s)){
	 	int i=0;
	 	for(; s[i]!='+'; i++){}
		int j=i+1;
		string s1 = s.substr(0,i);
		reverse(s1.begin(), s1.end());
		int a = stoi(s1);
		for(; s[i]!='='; i++){}		
		s1 = s.substr(j,i-j);
		reverse(s1.begin(), s1.end());
		int b = stoi(s1);
		s1 = s.substr(i+1,s.size()-(i+1));
		reverse(s1.begin(), s1.end());
		int c = stoi(s1);
		if((a+b)==c) cout << "True" << '\n';
		else cout << "False\n";
	}
 	return 0;
}