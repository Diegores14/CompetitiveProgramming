#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> comp;
vector<bool> used;

void DFS(vector<vector<int>> & v, int a, int b){
	used[a]=true;comp[b].push_back(a);
	for(int i=0; i<(int)v[a].size(); i++){
		if(!used[v[a][i]])DFS(v, v[a][i], b);
	}
} 

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, v, e;
	char a, b;
	cin >> n;
	for(int i=1; i<=n; i++){
	 	cin >> v >> e;
	 	vector<vector<int>> G(v);
	 	comp.erase(comp.begin(), comp.end());
	 	used.assign(v, false);
	 	while(e--){ cin >> a >> b; G[(int)(a-'a')].push_back((int)(b-'a'));G[(int)(b-'a')].push_back((int)(a-'a'));}
		for(int j=0; j<v; j++){
			if(!used[j]){
			 	comp.push_back(vector<int>());
				DFS(G, j, comp.size()-1);
			}
		}
		cout << "Case #" << i << ":\n";
		for(int j=0; j<(int)comp.size(); j++){
			sort(comp[j].begin(),comp[j].end());
		 	for(int k=0; k<(int)comp[j].size(); k++)cout << (char)(comp[j][k]+'a') << ',';
		 	cout << '\n';
		}
		cout << comp.size() << " connected components\n\n";
	}
	return 0;
}