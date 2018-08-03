#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct node{
	int b;
	long long c;
	bool p;
	set<ii> m;
	node(int _b, long long _c,bool _p, set<ii> _m){b=_b; c=_c; p=_p; m=_m;}
};

bool operator <(node a, node b){
	return a.c > b.c;
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<list<ii>> g(n);
	for(int i=0; i<m; i++){ cin >> a >> b >> c; g[a-1].push_back(ii(b,c)); g[b-1].push_back(ii(a,c));}
	priority_queue<node> q;
	set<ii> s, aux;
	long long d;
	bool p;
	q.push(node(0, 0, false, s));
	while(!q.empty() && (!q.top().p || q.top().b != n-1)){
		a = q.top().b;
		d = q.top().c;
		p = q.top().p;
		aux = q.top().m;
		q.pop();
		for(ii to : g[b])
			if(aux.count(ii(a,to.first))==0){
				set<ii> aux1 = aux;
			 	aux1.insert(ii(a,to.first));
			 	q.push(node(to.first, d+to.second, !p, aux1));
			}
	}
	if(q.empty()) cout << "-1\n";
	else cout << q.top().c << '\n';
	return 0;
}