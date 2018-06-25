#include <bits/stdc++.h>
using namespace std;

struct node{
  	int index, kuronumber;
	node(int i, int k){index=i; kuronumber=k;}
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N, K, u, s;
	while(cin >> N >> K){
		int cont=0, maximo=0;
		bool res=false;      
		vector<vector<int>> v(N);  
		for(int i = 1; i<N; i++){
	 		cin >> u >> s;
			u--;s--;
			v[u].push_back(s);
			//v[s].push_back(u);
		}             
		for(int i=0; i<N; i++){
			queue<node> q;
			cont=0;
			vector<bool> used(N,false);
			q.push(node(i,0));
			used[i] = true;
			while(q.front().kuronumber!=K && !q.empty()){
				for(int to : v[q.front().index]){
			 		if(!used[to]){
			 			q.push(node(to,q.front().kuronumber+1));
						used[to]=true;
					}
				}                                     
				cont++;
				q.pop();
			} 
			if(!q.empty()){res=true; maximo = max(maximo, cont+(int)q.size());}
		}
		if(res) cout << maximo << '\n';
		else cout << "Impossible revenge!\n";
	}
	return 0;
}