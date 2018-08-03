#include <bits/stdc++.h>
using namespace std;

int cont;
vector<bool> used;

void DFS(vector<list<int>> & v, int i){
 	used[i]=true;
 	cont++;
	for(int to : v[i])
		if(!used[to])DFS(v, to);
	cont++;
}

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, v, a, aux1, aux2;
	cin >> t;
	while(t--){
	 	cin >> n >> v >> a;	 	
	 	vector<list<int>> g(v);
	 	cont=0;
	 	used.assign(v,false);
		for(int i=0; i<a; i++){cin >> aux1 >> aux2; g[aux1].push_back(aux2); g[aux2].push_back(aux1);}
		DFS(g, n);
		cout << cont-2 << '\n';
	}
 	return 0;
}