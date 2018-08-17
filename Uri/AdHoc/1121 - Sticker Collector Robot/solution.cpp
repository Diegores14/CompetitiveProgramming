#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, s;
	char c;
	string s1;
	while(cin >> n >> m >> s, n || m || s){
		int ans = 0;
	 	vector<vector<char>> v(n, vector<char> (m));
	 	pair<int,int> p;
	 	for(int i=0; i<n; i++){
	 	 	for(int j=0; j<m; j++){
	 	 	 	cin >> v[i][j];
	 	 	 	if(v[i][j]=='N' || v[i][j]=='S' || v[i][j]=='L' || v[i][j]=='O'){
					p.first=i;
					p.second=j;
				}
	 	 	}
	 	}
	 	cin >> s1;
		for(int i=0; i<s; i++){
			c=s1[i];
			//cout << c << "hola\n";
			int x = p.first, y = p.second;
			if(c=='D'){
				if(v[x][y]=='N'){v[x][y]='L'; continue;}
				if(v[x][y]=='L'){v[x][y]='S'; continue;}
				if(v[x][y]=='S'){v[x][y]='O'; continue;}
				if(v[x][y]=='O'){v[x][y]='N'; continue;}
			}
			if(c=='E'){
				if(v[x][y]=='N'){v[x][y]='O'; continue;}
				if(v[x][y]=='L'){v[x][y]='N'; continue;}
				if(v[x][y]=='S'){v[x][y]='L'; continue;}
				if(v[x][y]=='O'){v[x][y]='S'; continue;}
			}
			if(c=='F'){				
				char aux = v[x][y];				
				//cout << aux << "hello";
				if(aux=='N')x--;
				if(aux=='L')y++;
				if(aux=='S')x++;
				if(aux=='O')y--;
				if(x>=n || y>=m || x<0 || y<0) continue;
				if(v[x][y]=='#') continue;
				v[p.first][p.second]='.';
				if(v[x][y]=='*'){ans++; v[x][y]='.';}                                               
			 	if(v[x][y]=='.'){v[x][y]=aux;p.first = x; p.second = y; continue;}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}