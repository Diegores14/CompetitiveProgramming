#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 	int n;
	string s;
	cin >> n;
	cin.ignore();
	while(n--){
	 	getline(cin, s);
		int med =s.size()/2-1;
		for(int i= med; i>=0; i--)cout << s[i];
		for(int i= s.size()-1; i>med; i--) cout << s[i];
		cout << '\n'; 
	}
	return 0;
}