#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class UnionFind{
	private: vi rank, p;
	public:
		UnionFind(int N){ rank.assign(N,0); p.assign(N, 0); for(int i=0; i<N; i++)p[i]=i;}
		int findSet(int i){ return (p[i]==i)? i : p[i]=findSet(p[i]);}
		int isSameSet(int i, int j){ return findSet(i) == findSet(j);}
		void unionSet(int i, int j){
		 	if(!isSameSet(i, j)){
		 		int x = findSet(i), y = findSet(j);
		 		if(rank[x]>rank[y]) p[y]=x;
		 		else{
		 		 	p[x] = y;
		 		 	if(rank[x]==rank[y]) rank[y]++;
		 		}
		 	}
		}
};


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m, a, b;
	cin >> t;
	for(int k=1; k<=t; k++){
		cout << "Caso #" << k <<": ";
		cin >> n >> m;
		UnionFind uf(n);
		for(int i=0; i<m; i++){ cin >> a >> b; uf.unionSet(a-1, b-1);}
		set<int> ans;
		for(int i=0; i<n; i++)ans.insert(uf.findSet(i));
		if(ans.size()==1) cout << "a promessa foi cumprida\n";
		else cout << "ainda falta(m) " << ans.size()-1 << " estrada(s)\n";
       	}
	return 0;
}