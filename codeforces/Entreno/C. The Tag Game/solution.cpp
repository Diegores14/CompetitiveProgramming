#include <bits/stdc++.h>
using namespace std;
vector<bool> used;

int DFS1(int i, int & x,vector<vector<int>> &edge, int cont){
	int mmax = 0;
	if(i==x)return (cont&1)? cont/2 : cont/2 - 1;
	if(!used[i]){
		used[i]=true;
		for(int to : edge[i]){
			if(!used[to])
				mmax = max(mmax, DFS1(to, x, edge, cont+1));
		}
		if(mmax>0){
			x = i;
			return mmax-1;
		}
	}
	return 0;
}

int DFS(int i, int x, vector<vector<int>> & edge, bool aux, int cont){
	int mmax= 0;
	if(!used[i]){
	 	used[i]=true;
		for(int to : edge[i]){
		 	if(!used[to]){
		 	 	if(x==i || aux)
					mmax = max(mmax, DFS(to, x,edge, true, cont+1));
				else
					mmax = max(mmax, DFS(to, x, edge, false, cont+1));
			}
		}
	}
	if(aux || i==x)
		return max(mmax, cont);
	else
		return mmax;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, x, a, b;
	cin >> n >> x;
	vector<vector<int>> edge(n);
	used.assign(n,false);
	for(int i=1; i<n; i++){
	 	cin >> a >> b;
		edge[a-1].emplace_back(b-1);
		edge[b-1].emplace_back(a-1);
	}
	x--;
	DFS1(0, x, edge, 0); 
	used.assign(n,false);
	cout << 2*DFS(0, x, edge, false, 0) << '\n';
	return 0;
}