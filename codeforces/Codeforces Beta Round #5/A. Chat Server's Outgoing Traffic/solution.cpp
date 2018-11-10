#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int ans = 0;
	set<string> chat;
	while(getline(cin, s)){
	 	if(s[0]=='+'){
			chat.insert(s.substr(1,s.size()-1));
		}else{
			if(s[0]=='-')
				chat.erase(s.substr(1,s.size()-1));
			else{
				int i;
			 	for(i=0; i<(int)s.size(); i++)
					if(s[i]==':')break;
				ans += ((s.size()-(i+1))*chat.size());				
			}
		}
	}
	cout << ans << '\n';
	return 0;
}