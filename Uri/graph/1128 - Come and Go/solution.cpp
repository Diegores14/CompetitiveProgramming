#include <bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<vector<int>> gt, comp;
vector<vector<int>> g;
vector<int> tim;

void DFS1(int nodo){
 	used[nodo]=true;
 	for(int to : g[nodo]) 
 		if(!used[to])DFS1(to);
	tim.push_back(nodo); 
}

void DFS2(int nodo, int i){
 	used[nodo]=true;
 	comp[i].push_back(nodo);
 	for(int to : gt[nodo]) 
 		if(!used[to])DFS2(to, i); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, c;
	while(cin >> n >> m, n || m){
	 	g.assign(n, vector<int>());
		gt.assign(n, vector<int>());
		comp.erase(comp.begin(), comp.end());
		tim.erase(tim.begin(), tim.end());
		used.assign(n,false);
		for(int i=0; i<m; i++){cin >> a >> b >> c; g[a-1].push_back(b-1); gt[b-1].push_back(a-1); if(c==2){g[b-1].push_back(a-1); gt[a-1].push_back(b-1);}}
		for(int i=0; i<n; i++)if(!used[i])DFS1(i);
		used.assign(n, false);
		reverse(tim.begin(), tim.end());
		for(int to : tim){ if(!used[to]){comp.push_back(vector<int>());DFS2(to, comp.size()-1);}}
		if(comp.size()==1)cout << "1\n";
		else cout << "0\n";
	} 	
 	return 0;
}