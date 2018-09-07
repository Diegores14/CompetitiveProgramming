#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	bool answer;
	while(cin >> n, n){
		answer = true;
		map<int, int> s;
		vector<pair<int,int>> v(n);
	 	for(int i=0; i<n; i++){
	 		cin >> v[i].first >> v[i].second;
			if(0 <= i+v[i].second && i+v[i].second < n && s.count(i+v[i].second)==0)s[i+v[i].second]=v[i].first;
			else answer=false;
		}
	 	int cont=0;
	 	if(answer) for(map<int, int>::iterator to = s.begin(); to != s.end(); to++){cont++; cout << to->second << ((cont==n)? '\n' : ' ');}
	 	else cout << "-1\n";
	}
	return 0;
}