#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n;
	bool esc;
	string s;
	cin >> n;
	cin.ignore();
	while(n--){
		esc=true;
	 	getline(cin, s);
		for(int i=0; i<(int)s.size(); i++){
		 	if(esc && s[i]!=' '){cout <<s[i];esc=false;}
			if(s[i]==' ')esc=true;
		}
		cout << '\n';
	}
	return 0;
}