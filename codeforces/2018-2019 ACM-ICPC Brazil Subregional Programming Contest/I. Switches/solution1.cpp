#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, aux, aux1;
	cin >> n >> m;
	vector<int> v(m, 0), balbs(m,0);
	map<vector<int>,vector<int>> s;
	cin >> aux; 
	for(int i=0; i<aux; i++){
		cin >> aux1;
		balbs[aux1-1] = 1;
	}
	for(int i=0; i<n; i++){
		cin >> aux;
		for(int j=0; j<aux; j++){
		 	cin >> aux1;
			v[aux1-1] = (v[aux1-1]? 0 : 1);
		}
		s[v].emplace_back(i+1);
	}
	for(int i=0; i<m; i++)
		v[i] ^= balbs[i];
	if(s.count(balbs))cout << s[balbs][0] << '\n';
	else{
	 	if(s.count(v))cout << s[v][0]+n << '\n';
		else cout << "-1\n";
	}
	return 0;
}