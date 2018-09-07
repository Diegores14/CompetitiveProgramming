#include <bits/stdc++.h>
using namespace std;
vector<list<int>> g;
vector<bool> used;
vector<int> dp;
vector<long long> dj;


struct node{
	int first;
	long long w;
	node(){first=0; w=0;}
	node(int a, long long c){first=a; w=c;}
};

bool operator <(node a, node b){
	return a.w > b.w;
}

int DFS(int n){
	if(used[n]) return dp[n];
	int ans=0;
	used[n]=true;
	for(int to : g[n]){
	 	ans = (ans%1000000007 + DFS(to)%1000000007)%1000000007;
	}
	return dp[n] = ans;
}

int dijkstra(vector<list<pair<int,int>>> & v, int b){
	priority_queue<node> q;
	q.push(node(0, 0));
	while(!q.empty()){
		int n = q.top().first;
		long long w = q.top().w;
		q.pop();
		//cout << n << "h " << w << '\n';
		if(!used[n]){
			used[n]=true;
			dj[n] = w;
			for(pair<int,int> to : v[n]){
				q.push(node(to.first, (w+to.second)));
			}
		}
	}
	return dj[b];
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, c;
	while(cin >> n >> m){
		used.assign(n, false);
		vector<list<pair<int,int>>> v(n);
		dj.assign(n,0);
		for(int i=0; i<m; i++){
	 		cin >> a >> b >> c;
		 	v[a].emplace_back(pair<int,int>(b,c));
		 	v[b].emplace_back(pair<int,int>(a,c));
		}
		g.assign(n, list<int>());
		cout << dijkstra(v, n-1) << " ";
		for(int i=0; i<n; i++){
			for(pair<int,int> to: v[i]){
		 		if((dj[i]+to.second) == dj[to.first]){
		 			g[i].emplace_back(to.first);
			 		//cout << i << ' ' << to.first << '\n';
			 	}
			}
		}
		used.assign(n, false);
		dp.assign(n,0);
		dp[n-1]=1;
		used[n-1]=true;
		cout << DFS(0) << '\n';
	}
 	return 0;
}