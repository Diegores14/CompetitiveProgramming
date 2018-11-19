#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	map<int, vector<int>> m;
	long long total = 0;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
		total += v[i];
		m[v[i]].emplace_back(i);
	}	
	set<int> s;
	for(int i=0; i<n; i++){
	 	long long aux = total - (v[i]<<1);
	 	if(aux <= 1e6 && m.count(aux)){
	 	 	for(auto it: m[aux])
	 	 		if(i!=it)
	 	 			s.insert(it);
	 	}
	}
	cout << s.size() << '\n';
	if(s.size()){
		bool salt = true;
	 	for(int i: s){
	 		if(salt)
	 			salt=false;
	 		else
	 			cout << ' ';
	 		cout << i+1;
		}
		cout << '\n';
	}
	return 0;
}