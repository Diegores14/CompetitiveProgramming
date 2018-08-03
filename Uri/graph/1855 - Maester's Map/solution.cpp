#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> used;

char answer(vector<vector<char>> & v){
	int j=0, i=0, di=0, dj=0; 
	if(v[i][j]== '<')dj=-1;
	if(v[i][j]== '>')dj=1;
	if(v[i][j]== '^')di=-1;
	if(v[i][j]== 'v')di=1;
 	while(v[i][j]!='*' && !used[i][j] && 0<=i && i<(int)v.size() && 0<=j && j<(int)v[i].size() && (di!=0 || dj != 0)){
		used[i][j]=true;
		if(v[i][j]== '<'){dj=-1;di=0;}
		if(v[i][j]== '>'){dj=1;di=0;}
		if(v[i][j]== '^'){di=-1;dj=0;}
		if(v[i][j]== 'v'){di=1;dj=0;}
		i+=di;
		j+=dj;
 	}
 	return (v[i][j]=='*')? '*' : '!';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(m, vector<char>(n,0));
	used.assign(m, vector<bool>(n,false));
	for(int i=0; i<m; i++){
	 	for(int j=0; j<n; j++)cin >> v[i][j];
	}
	cout << answer(v) << '\n';
	return 0;
}