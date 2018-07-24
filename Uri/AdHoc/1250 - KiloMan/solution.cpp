#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, answer;
	string s;
	cin >> t;
	while(t--){
		answer=0;
	 	cin >> n;
	 	vector<int> v(n);
		for(int i=0; i<n; i++)cin >> v[i];
		cin >> s;
		for(int i=0; i<n; i++)if((v[i]<=2 && s[i]=='S') || (v[i]>2 && s[i]=='J'))answer++;
		cout << answer << '\n';
	}
	return 0;
}