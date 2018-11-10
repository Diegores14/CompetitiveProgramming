#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	map<string, int> m;
	cin >> n;
	while(n--){
		cin >> s;
		if(m.count(s)==0){
			cout << "OK";
			m[s]=0;
		}
		else{
			m[s]++;
			cout << s << m[s];
		}
		cout << '\n';
	}
	return 0;
}