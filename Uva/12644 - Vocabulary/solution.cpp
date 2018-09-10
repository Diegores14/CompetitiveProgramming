#include <bits/stdc++.h>
using namespace std;

int answer(vector<vector<int>> & v){
	priority_queue<int>
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	string s;
	while(cin >> a >> b){
	 	string s;
		vector<vector<int>> v(a,vector<int>(26, 0)), g(b+a+1);
		for(int i=0; i<a; i++){
		 	cin >> s;
			for(char to : s) v[i][to-'a']++;
		}
		for(int i=0; i<b; i++){
		 	cin >> s;
			vector<int> aux(26,0);
			for(char to : s) aux[to-'a']++;
			for(int j=0; j<a; j++){
				bool r=true;
				for(int k=0; k<26; k++) if(v[j][k]<aux[k]){r=false; break;}
				if(r)g[i].emplace_back(j+b);
			}
		}
		for(int i=b; i<b+a; i++)g[i].push_back(g.size()-1);

	}
	return 0;
}