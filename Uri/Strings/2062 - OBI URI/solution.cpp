#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n;
	string s;
	cin >> n;
	while(n--){
	 	cin >> s;
		if(s.size()==3){
		 	if((s[0]=='O' && s[1]=='B') || (s[0]=='U' && s[1]=='R'))s[2]='I'; 
		}
		cout << s;
		if(n) cout << ' ';
		else cout << '\n';
	}
	return 0;
}