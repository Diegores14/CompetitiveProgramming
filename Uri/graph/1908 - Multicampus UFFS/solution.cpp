#include <bits/stdc++.h>
using namespace std;

struct node{
 	int index, cost;
	node(int i, int c){index=i; cost=c;}
};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N, K, L, aux1;
	cin >> N >> K;
	queue<node> q;
	vector<vector<int>> v(N);
	vector<bool> used(N,false);
	while(K--){
	 	cin >>L; 
		vector<int> aux;           
		while(L--){
	         	cin >> aux1;
			aux.push_back(--aux1);
		}                  
		for(int to : aux)for(int to1: aux)v[to].push_back(to1);
	}
	q.push(node(0,0));
	used[0]=true;
	while(q.front().index!=N-1){
		int cost = q.front().cost;
		for(int to : v[q.front().index])
			if(!used[to]){
				q.push(node(to,cost+1));
				used[to]=true;
			}
		q.pop();
	}
	cout <<  q.front().cost << '\n';
 	return 0;
}