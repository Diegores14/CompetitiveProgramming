#include <bits/stdc++.h>
using namespace std;

struct node{
  	int x, y, t;
	node(){}
};

int dp[25][25][2005];

int busqueda(vector<node> & v,int x, int y, int t){
	int result=0;
 	for(int i=0; i<(int)v.size(); i++)
 		if(v[i].x==x && v[i].y==y && v[i].t==t)
 			result++;
	return result;
} 

int answer(vector<node> & v, int x, int y, int t, int n , int m){
	if(t>v[v.size()-1].t || x <=0 || y<=0 || x>n || y>m) return 0;
	if(dp[x][y][t]!=-1)return dp[x][y][t];
	int best=busqueda(v, x, y, t), mx=0;
	mx=max(mx,answer(v, x, y, t+1, n, m));	
	mx=max(mx,answer(v, x+1, y, t+1, n, m));
	mx=max(mx,answer(v, x+1, y+1, t+1, n, m));
	mx=max(mx,answer(v, x, y+1, t+1, n, m));
	mx=max(mx,answer(v, x-1, y+1, t+1, n, m));
	mx=max(mx,answer(v, x-1, y, t+1, n, m));
	mx=max(mx,answer(v, x-1, y-1, t+1, n, m));
	mx=max(mx,answer(v, x, y-1, t+1, n, m));
	mx=max(mx,answer(v, x+1, y-1, t+1, n, m));
	return dp[x][y][t] = best + mx;
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, k, x, y;
	while(cin >> n >> m >> k, n || m || k){
		memset(dp, -1, sizeof dp);
		vector<node> v(k);
		for(int i=0; i<k; i++)cin >> v[i].x >> v[i].y >> v[i].t;
		cin >> x >> y;
		cout << answer(v, x, y, 0, n, m) << '\n';
	}
	return 0;
}