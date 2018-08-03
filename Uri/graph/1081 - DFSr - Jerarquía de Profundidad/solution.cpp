#include <bits/stdc++.h>
using namespace std;

vector<bool> used;

void DFS(vector<vector<int>> & v, int b, int i){
	used[i]=true;
	for(int k=0; k<(int)v[i].size()-1; k++){		
		if(v[i][k]==1){
			for(int j=0; j<b; j++)cout << ' ';
			cout << i << '-' << k;
			if(!used[k]){ cout << " pathR(G," << k << ")\n"; DFS(v, b+2, k);}
			else cout << '\n';
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, v, e, a, b;
	cin >> t;
	for(int i=1; i<=t; i++){
	 	cin >> v >> e;
	 	used.assign(v, false);
	 	vector<vector<int>> g(v, vector<int>(v+1,0));
		while(e--){
			cin >> a >> b;
			g[a][b]=1;
			g[a][v]++;
		}
		cout << "Caso " << i <<":\n";
		for(int j=0; j<v; j++)if(!used[j] && g[j][v]){ DFS(g, 2, j);cout << '\n';} 
	}
 	return 0;
}