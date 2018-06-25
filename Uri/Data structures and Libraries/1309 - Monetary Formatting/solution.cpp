#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	int a;
	while(cin >> s >> a){
	 	cout << '$' << s[0];
		for(int i=1; i<(int)s.size(); i++){
		 	if(!((s.size()-i)%3))cout << ',';
			cout << s[i];
		}
		cout << '.';
		if(a<10)cout << '0';
		cout << a << '\n';
	}
	return 0;
}