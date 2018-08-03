#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

class UnionFind{
	private:  vi rank, p;
	public:
	UnionFind(int N){ rank.assign(N, 0); p.assign(N, 0); for(int i=0; i<N; i++)p[i]=i;}
	int findSet(int i){ return (p[i]==i)? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){ return findSet(i) == findSet(j);}
	void unionSet(int i, int j){
	 	if(!isSameSet(i, j)){
	 	 	int x=findSet(i), y=findSet(j);
	 	 	if(rank[x] > rank[y])p[y]=x;
	 	 	else{
	 	 	 	p[x]=y;
	 	 	 	if(rank[x] == rank[y]) rank[y]++;
	 	 	}
		}
	}

};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, c, answer=0;
	cin >> n >>m;
	vector<pair<int, ii>> edges(m);
	UnionFind uf(n);
	for(int i=0; i<m; i++){ cin >> a >> b >> c; edges[i].second.first = a-1; edges[i].second.second = b-1; edges[i].first = c;}
	sort(edges.begin(), edges.end());
	for(int i=0; i<m; i++)
		if(!uf.isSameSet(edges[i].second.first, edges[i].second.second)){
		 	uf.unionSet(edges[i].second.first, edges[i].second.second);
			answer+=edges[i].first; 
		}
	cout << answer << '\n'; 
	return 0;
}