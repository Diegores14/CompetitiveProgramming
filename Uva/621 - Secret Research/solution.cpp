#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n;
	string s;
	while(n--){
	 	cin >> s;
		if(s == "1" || s == "4" || s == "78"){
		 	cout << "+\n";
			continue;
		}
		if(s.size()>1 && s[s.size()-1] == '5' && s[s.size()-2] == '3'){
		 	cout << "-\n";
			continue;
		}
		if(s.size()>1 && s[0] == '9' && s[s.size()-1] == '4'){
		 	cout << "*\n";
			continue;
		}
		if(s.size()>2 && s[0] == '1' && s[1] == '9' && s[2] == '0'){
		 	cout << "?\n";
			continue;
		}
		cout << "?\n";
	}
	return 0;
}