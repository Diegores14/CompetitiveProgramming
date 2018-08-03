#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

class UnionFind{
  	private: vi p, rank;
  	public: UnionFind(int N){ rank.assign(N, 0);
  		p.assign(N,0); for(int i=0; i<N; i++)p[i]=i;}
  		int findSet(int i){ return (p[i]== i)? i : (p[i]=findSet(p[i]));}
  		bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
  		void unionSet(int i, int j){
  		 	if(!isSameSet(i, j)){
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y])p[y]=x;
				else{ p[x] = y; if(rank[x] == rank[y]) rank[y]++;}
  		 	}
  		}

};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, cost;
	while(cin >> n >> m, n || m){
		cost=0;
		vector<pair<int,ii>> listEdges(m);
		for(int i=0; i<m; i++)cin >> listEdges[i].second.first >> listEdges[i].second.second >> listEdges[i].first;
		sort(listEdges.begin(), listEdges.end());
		UnionFind uf(n);
		for(int i=0; i<m; i++){             
		 	if(!uf.isSameSet(listEdges[i].second.first, listEdges[i].second.second)){		 
	 	 		uf.unionSet(listEdges[i].second.first, listEdges[i].second.second);
	 		}else cost+=listEdges[i].first;
		}
		cout <<  cost << '\n';
	}
	return 0;
}