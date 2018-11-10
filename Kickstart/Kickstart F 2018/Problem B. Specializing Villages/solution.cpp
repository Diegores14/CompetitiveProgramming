#include <bits/stdc++.h>
using namespace std;

int dp[10];

struct edge{
	int b, l;
	node(){b=0; l=0;}
	node(int _b, int _l){
	 	b=_b;
		l=_l;
	}
}

int dismin(int idx, vector<vector<edge>> & edges, const int &combina, int com){
	if(dp[idx]!=-1 && ((combina>>idx)&1) == com){
		return dp[idx];
	}else{
		int mmin = 1000000000;
		for(edge to : edges[idx]){
			mmin = min(mmin, to.l+dismin(to.b, ))
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, v, e, a, b, l;
	cin >> t;
	for(int c=1; c<=t; c++){
		cin >> v >> e;
		vector<vector<edge>> edges(v);
		for(int i=0; i<e; i++){
		 	cin >> a >> b >> l;
			edges[a-1].emplace_back(edge(b-1, l));
			edges[b-1].emplace_back(edge(a-1, l));
		}
		top=(1<<v);
		for(int combina = 1; combina<top; combina++){
			memset(dp, -1, sizeof dp);
			for(int i=0; i<v; i++){
			 	dismin(i, edges, combina, (combina>>i)&1) 
			}
		}
	}
	return 0;
}