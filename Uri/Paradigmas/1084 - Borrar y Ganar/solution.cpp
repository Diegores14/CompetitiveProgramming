#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, d, aux, mayor;
	string s;
	while(cin >> n >> d, n || d){
	 	cin >> s;
		aux=n-d;
		mayor=n;
		set<int> se;
		vector<vector<int>> v(n, vector<int>(10,0));
		for(int i=0; i<n; i++)v[i][s[i]-'0']=1;
		for(int i=9; i>=0; i--){
			if(aux==mayor)break;
		 	for(int j=n; j>=0; j--)if(v[j][i]){se.insert(j); mayor=min(n-(j+1),mayor); aux--;} 
		} 
		for(set<int>::iterator it=se.begin(); it!=se.end(); it++) cout << s[*it];
		cout << '\n';
	}
	return 0;
}