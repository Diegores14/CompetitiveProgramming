#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int dp[205][10005][2];

class UnionFind{
	public:
	vi p, rank, pary, nopary, valor;
	UnionFind(int n, int m, vector <int> valores){
		valor = valores;
	 	p.assign(n, 0);
	 	rank.assign(n, 1);
	 	pary.assign(n, 0);
	 	nopary.assign(n, 0);
		for(int i=0; i<n; i++){
			p[i]=i;
			if(i<m)
				pary[i] = 1;
			else
				nopary[i] = 1;
		}
	}
	int findSet(int i){ return (p[i]==i)? i : (p[i] = findSet(p[i]));}
	bool isSame(int i, int j){ return findSet(i) == findSet(j);}
	void unionSet(int i, int j){
	 	if(!isSame(i, j)){
	 		int x = findSet(i), y = findSet(j);
			if(rank[x]>=rank[y]){
			 	p[y] = x;
				rank[x] += rank[y];
				pary[x] += pary[y];
				nopary[x] += nopary[y];
				valor[x] += valor[y];
			}else{
			 	p[x] = y;
				rank[y] += rank[x];
				pary[y] += pary[x];
				nopary[y] += nopary[x];
				valor[y] += valor[x];
			}
		}
	}
};

int solution(int idx,UnionFind & uf, vector<int> & v, int money, bool group){
	if(v.size() == idx) return 0;
	if(dp[idx][money][group] != -1) return dp[idx][money][group];
	if(money-uf.valor[v[idx]] < 0) return dp[idx][money][group] = solution(idx+1, uf, v, money, group);
	int cant;
	if(group)
		cant = uf.pary[v[idx]] - uf.nopary[v[idx]];
	else
		cant = uf.nopary[v[idx]] - uf.pary[v[idx]];
	if(cant>0)
		return dp[idx][money][group] = max(solution(idx+1, uf, v, money, group), solution(idx+1, uf, v, money-uf.valor[v[idx]], group)+cant);
	else
		return dp[idx][money][group] = solution(idx+1, uf, v, money, group);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int d, p, r, b, i, j;
	while(cin >> d >> p >> r >> b){
	        vector<int> v(d+p,0);
		for(int i=0; i<d; i++){
		 	cin >> v[i];
		}
		for(int i=0; i<p; i++){
		 	cin >> v[i+d];
		}
		UnionFind uf(d+p, d, v);
		for(int k=0; k<r; k++){
			cin >> i >> j;
			uf.unionSet(i-1, j+d-1);
		}
		set<int> s;
		int limit = d+p;
		for(i=0; i<limit; i++){
		 	s.insert(uf.findSet(i));
		}
		vector<int> aux(s.size());
		j=0;
		for(int k : s){
		 	aux[j] = k;
			j++;
			//cout << uf.pary[k] << ' ' << uf.nopary[k] << ' ' << uf.valor[k] << '\n';
		}
		memset(dp, -1, sizeof dp);                         
		cout << solution(0, uf, aux, b, 0) + d <<  ' ' <<  solution(0, uf, aux, b, 1) + p << '\n';
	}	
	return 0;
}