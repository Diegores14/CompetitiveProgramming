#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef long long LL;
struct edge{
	int u, v;
	LL cap, flow;
	edge(){}
	edge(int u, int v, LL cap):u(u), v(v), cap(cap), flow(0) {} 
};

struct dinic{
	int N;
	vector<edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
	void add_edge(int u, int v, LL cap){
		if(u != v){
			E.emplace_back(edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(edge(v, u, 0));
			g[v].emplace_back(E.size()-1);
		}
	}
	bool bfs(int S, int T){
	 	queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while(!q.empty()){
		 	int u = q.front(); q.pop();
			if(u == T) break;
			for(int k: g[u]){
			 	edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1){
				 	d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}

	LL dfs(int u, int T, LL flow = -1){
	 	if(u == T || flow == 0) return flow;
		for(int &i = pt[u]; i< int(g[u].size()); ++i){
		 	edge &e = E[g[u][i]];
			edge &oe = E[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1){
			 	LL amt = e.cap - e.flow;
				if(flow != -1 && amt > flow) amt = flow;
				if(LL pushed = dfs(e.v, T, amt)){
				 	e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}

		}
		return 0;
	}

	LL max_flow(int S, int T){
		LL total = 0;
		while(bfs(S, T)){
		 	fill(pt.begin(), pt.end(), 0);
			while(LL flow = dfs(S, T))
				total += flow;
		}
		return total;
	}
};

bool IsTrue(int t, long long & suma, vector<pair<int, ii>> & v, vector<int> &v1, vector<int> &v2){
	int n = v1.size()+v2.size()+1;
	dinic d(n+1);
	for(int i=1; i<=(int)v1.size(); i++)
		d.add_edge(0, i, v1[i-1]);
	for(int i=0; i<(int)v.size() && v[i].first<=t; i++){
		d.add_edge(v[i].second.first, v1.size()+v[i].second.second, 1000000000);
	}
	for(int i=1; i<=(int)v2.size(); i++)
		d.add_edge(i+v1.size(), n, v2[i-1]);
	//cout << "hello\n";
	return d.max_flow(0, n)==suma;
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p, r, c, l=-1, R=0;
	long long sum=0;
	cin >> p >> r >> c;
	vector<int> v1(p), v2(r);
	vector<pair<int, ii>> v3(c);
	for(int i=0; i<p; i++){
		cin >> v1[i];
		sum+=v1[i];
	}
	for(int i=0; i<r; i++)
		cin >> v2[i];
	for(int i=0; i<c; i++){
		cin >> v3[i].second.second >> v3[i].second.first >> v3[i].first;
		R = max(R, v3[i].first);
	}
	sort(v3.begin(), v3.end());
	R++;
	bool ans = false;
	while((R-l)!=1){
		//cout << l << ' ' << R;
		int mid = (l+R)>>1;
		if(IsTrue(mid, sum, v3, v2, v1)){
			R=mid;
			ans = true;
		}
		else l=mid;
	}
	if(ans)cout << R << '\n';
	else cout << "-1\n";
	return 0;
}