#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct node{
  	int first, second;
  	node(int a, int b){ first = a; second = b;}
};

bool operator <(node a, node b){
 	return a.second > b.second;
}

int dijkstra(vector<list<ii>> & v, int c, int k){
	vector<bool> used(v.size(), false);
	priority_queue<node> q;
	q.push(node(k,0));
	while(!q.empty() && q.top().first != c-1){		
	 	int u = q.top().first;
	 	int p = q.top().second;	 	
		q.pop();
		if(!used[u]){
		used[u] = true;
		if(u<c){
			if(!used[u+1]){
				for(ii to : v[u])				
				if(u+1 == to.first){q.push(node(to.first, p+to.second));break;}
			}
		}else{ 
			for(ii to : v[u])
				if(!used[to.first]){				
					q.push(node(to.first, p+to.second));
				}
		}
		}
	}
	return q.top().second;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, c, k, a, u, p;
	while(cin >> n >> m >> c >> k, n || m || c || k){
		vector<list<ii>> v(n);
	 	for(int i=0; i<m; i++){
	 		cin >> u >> a >> p; 
	 		v[u].push_back(ii(a, p));
	 		v[a].push_back(ii(u, p));
		}
		cout << dijkstra(v, c, k) << '\n';
	}
	return 0;
}