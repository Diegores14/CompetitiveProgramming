#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int t;
	string s;
	cin >> t;
	while(t--){
	 	cin >> s;
		for(int i=0; i<(int)s.size()/2;i+=2)cout << s[i];
		cout << '\n'; 
	}
}