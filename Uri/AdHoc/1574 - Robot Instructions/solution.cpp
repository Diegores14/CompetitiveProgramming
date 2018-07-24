#include <bits/stdc++.h>
using namespace std; 


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, answer;
	string s;
	cin >> t;
	while(t--){
		cin >> n;
		answer=0;
		cin.ignore();
		vector<int> v(n+1, 0);
		for(int i=1; i<=n; i++){
		 	getline(cin, s);
		 	if(s[0]=='L')v[i]=-1;
			if(s[0]=='R')v[i]=1;
			if(s[0]=='S'){v[i]=v[stoi(s.substr(8,s.size()-8))];}
			answer+=v[i];
		}
		cout << answer << '\n';
	}
 	return 0;
}