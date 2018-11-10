#include <bits/stdc++.h>
using namespace std;

struct node{
	string s;
	int n;
	map<int,int> m;
	node(){n=0;}
};

bool operator <(node a, node b){
	if(a.n == b.n){
		int x=1000000000, y=1000000000;
		for(pair<int, int> to : a.m)
			if(to.first>=a.n)
				x=min(x, to.second);
		for(pair<int, int> to : b.m)
			if(to.first>=b.n)
				y=min(y, to.second);
		return x < y;
	}
	else return a.n > b.n;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	map<string, int> m;
	string aux;
	int aux1;
	cin >> n;
	vector<node> v;
	for(int i=0; i<n; i++){
	 	cin >> aux >> aux1;
		if(m.count(aux)==0){m[aux]=v.size(); v.emplace_back(node());}
		//cout << m[aux] << '\n';
		v[m[aux]].s=aux;
		v[m[aux]].n+=aux1;
		if(v[m[aux]].m.count(v[m[aux]].n)==0)v[m[aux]].m[v[m[aux]].n]=i;
	}
	sort(v.begin(), v.end());
	cout << v[0].s << '\n';
	return 0;
}