#include <bits/stdc++.h>
using namespace std;

vector<bool> used;
struct node{
	int a, b;
	node(int _a, int _b){a=_a; b=_b;}
};

bool operator <(node a, node b){
	return a.a > b.a;
}

int answer(vector<vector<int>> & v, int a, int b){
 	priority_queue<node> l;
 	int j, k;
	l.push(node(0, a));
	while(!l.empty() && l.top().b != b){
		if(!used[l.top().b]){
			used[l.top().b]=true;
			j=l.top().b;
			k=l.top().a;
			l.pop();
		 	for(int i=0; i<(int)v.size(); i++)
		 		if(!used[i] && v[j][i]!=-1){
		 			if(v[i][j]!=-1) l.push(node(k, i));
					else l.push(node(k + v[j][i], i));
				}
		}else l.pop();
	}
	return (l.empty())? -1: l.top().a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, e, k, a, b, c;
	while(cin >> n >>e, n || e){
	        vector<vector<int>> v(n, vector<int>(n,-1));
	        for(int i=0; i<e; i++){cin >> a >> b >> c; v[a-1][b-1]=c;}
	        /*for(int i=0; i<n; i++){
	         	for(int j=0; j<n; j++)cout << v[i][j] << ' ';
	         	cout << '\n';
	        }*/
	 	cin >> k;
		while(k--){
		 	cin >> a >> b;
		        used.assign(n,false);
		        c=answer(v, a-1, b-1);
		        if(c!=-1) cout <<  c << '\n';
		        else cout << "Nao e possivel entregar a carta" << '\n';
		}
		cout << '\n';
	}
 	return 0;
}