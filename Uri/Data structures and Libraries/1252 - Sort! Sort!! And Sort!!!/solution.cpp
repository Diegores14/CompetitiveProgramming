#include <bits/stdc++.h>
using namespace std;

struct node{
 	int valor, modulo;
	node(){}
	node(int v, int m){valor=v;modulo=m;}
};

bool operator <(node a, node b){
 	int x=a.valor%2, y=b.valor%2;
	if(a.modulo != b.modulo) return a.modulo < b.modulo;
	if(y && x)return a.valor > b.valor;
	if(!y && !x)return a.valor < b.valor;
	if(x)return true;
	if(y)return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, aux, m;
	while(cin >> n >> m, n||m){
		cout << n << ' ' << m << '\n';
	 	vector<node> v(n);
		for(int i=0; i<n; i++){cin >> aux; v[i]=node(aux,aux%m);}
		sort(v.begin(),v.end());
		for(node to : v)cout << to.valor << '\n';
	}
	cout << "0 0\n";
 	return 0;
}