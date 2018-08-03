#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

class UnionFind{
	private: vi rank, p;
	public:
		UnionFind(int N){ rank.assign(N, 0); p.assign(N, 0); for(int i=0; i<N; i++)p[i] = i;}
		int findSet(int i){ return (p[i]==i)? i : p[i]= findSet(p[i]);}
		bool isSameSet(int i, int j){ return findSet(i) ==findSet(j);}
		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
			 	int x = findSet(i), y = findSet(j);
			 	if(rank[x] > rank[y])p[y] = x;
			 	else{
			 	 	p[x] = y;
			 	 	if(rank[x] == rank[y])rank[y]++;
			 	}
			}	 
	        }
};


int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n;
	cin >> t;
	cout << fixed << setprecision(2);
	while(t--){
		long double answer=0;
		cin >> n;
	 	vector<ii> v(n);
	 	vector<pair<double, ii>>  edges;
	 	for(int i=0; i<n; i++){
	 		//cout << "Halo " << i << '\n';
	 		cin >> v[i].first >> v[i].second;
	 		for(int j=0; j<i; j++){
	 			edges.emplace_back(pair<double,ii>(sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second)), ii(i,j)));
	 		}
		}

	 	sort(edges.begin(), edges.end());
		UnionFind UF(n);
		for(int i=0; i<(int)edges.size(); i++)
			if(!UF.isSameSet(edges[i].second.first, edges[i].second.second)){
			 	UF.unionSet(edges[i].second.first, edges[i].second.second);
			 	answer += edges[i].first;
			}
		cout << answer/100.0 << '\n';
	}
	return 0;
}