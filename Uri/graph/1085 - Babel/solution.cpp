#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> is;
map<string, int> m;
struct node{
	string first, word;
	int second;
	node(string a, string c, int b){ first = a; word = c; second = b;}
};

bool operator <(node a, node b){
	return a.second > b.second;
}

int dijkstra(vector<list<is>> & v, string a, string b){
 	set<is> used;
	priority_queue<node> q;
	q.push(node(a, "\n", 0));
	while(!q.empty() && q.top().first != b){
	 	string u = q.top().first, w = q.top().word;
	 	int p = q.top().second;
	 	q.pop();
	 	if(used.count(is(u, w))==0){
	 	 	used.insert(is(u, w));
	 	 	for(is to: v[m[u]]){
	 	 	 	if(used.count(is(to.first, w))==0 && w[0] != to.second[0])
	 	 	 		q.push(node(to.first, to.second, p+to.second.size()));
	 	 	}
	 	}
	}
	return (q.empty())? -1 : q.top().second;
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s1, s2, aux1, aux2, aux3;
	while(cin >> n, n){
		m.erase(m.begin(), m.end());
	 	vector<list<is>> v(2);
	 	cin >> s1 >> s2;
		m[s1]=0;
		m[s2]=1;
	 	for(int i=0; i<n; i++){
	 	 	cin >> aux1 >> aux2 >> aux3;
			if(m.count(aux1)==0){
				m[aux1]=v.size();
				v.emplace_back(list<is>());
			}
			if(m.count(aux2)==0){
				m[aux2]=v.size();
				v.emplace_back(list<is>());
			}
			v[m[aux1]].push_back(is(aux2, aux3));
			v[m[aux2]].push_back(is(aux1, aux3));
	 	}
	 	int ans = dijkstra(v, s1, s2);
	 	if(ans==-1) cout << "impossivel\n";
	 	else cout << ans << '\n';
	}
	return 0;
}