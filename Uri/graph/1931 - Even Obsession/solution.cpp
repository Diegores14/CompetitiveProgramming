#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct node{
	int first;
	long long second;
	node(int a, long long b){ first = a; second = b;}
};

bool operator <(node a, node b){
 	return a.second > b.second;
}

long long dijkstra(vector<list<ii>> & v){
	vector<bool> used(v.size(), false);
	priority_queue<node> q;
	q.push(node(0,0));
	while(!q.empty() && q.top().first!=(int)v.size()-1){
	 	int a = q.top().first;
	 	long long b = q.top().second;
	 	q.pop();
	 	if(!used[a]){
	 		used[a] = true;
		 	for(ii to : v[a]){
	 		 	for(ii i: v[to.first])
		 	 		if(!used[i.first])
		 	 			q.push(node(i.first, b + to.second + i.second));
		 	}
	 	}
	}
	return (q.empty())? -1 : q.top().second;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int c, v, a, b, d;
	cin >> c >> v;
	vector<list<ii>> g(c);
	for(int i=0; i<v; i++){
	 	cin >> a >> b >> d;
	 	g[a-1].push_back(ii(b-1, d));
	 	g[b-1].push_back(ii(a-1, d));
	}
	cout << dijkstra( g) << '\n';
	return 0;
}