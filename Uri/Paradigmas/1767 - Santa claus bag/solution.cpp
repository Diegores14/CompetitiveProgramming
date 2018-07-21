#include <bits/stdc++.h>
using namespace std;

struct node{
	int first, second, third;
	node(int a, int b, int c):first(a), second(b),third(c){}
	node(){first=0; second=0; third=0;}
};

typedef pair<int,int> pii;
map<pii, node> m;

node knapsack(vector<int> & g, vector<int> & weight, int i, int w){
 	if(w==0 || i==0) return node();
 	if(m.count(pii(i-1,w)))return m[pii(i-1,w)];
 	if(w>=weight[i-1]){ 
 		node a = knapsack(g, weight, i-1, w-weight[i-1]);
 		node b = knapsack(g, weight, i-1, w);
 		if(a.first + g[i-1] > b.first)return m[pii(i-1,w)]=node(a.first+g[i-1], a.second+1, a.third+weight[i-1]);
 		else return m[pii(i-1,w)] = b;
 	}else {
 	 	return m[pii(i-1,w)] = knapsack(g, weight, i-1, w);
 	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n ;
	cin >> t;
	while(t--){
	 	cin >> n;
	 	m.erase(m.begin(),m.end());
	 	vector<int> qt(n), weight(n);
	 	for(int i=0; i<n; i++){ cin>>qt[i]; cin >> weight[i];}
	 	node a = knapsack(qt, weight, n, 50);
	 	cout << a.first << " brinquedos\n";
	 	cout << "Peso: " << a.third << " kg\n";
	 	cout << "sobra(m) " << n - a.second << " pacote(s)\n\n";
	}
 	return 0;
}