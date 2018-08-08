#include <bits/stdc++.h>
using namespace std;
vector<int> al;

int DFS(vector<vector<int>> & v, vector<bool> & used, vector<int> & r, int i){
 	used[i]=true;
 	//int x=i;
 	//while(al[x]!=i){x=al[x];}
 	int ans = r[i];                                  
 	for(int j=0; j<(int)v[i].size(); j++){
 	 	if(v[i][j]==1){
 	 		if(!used[j]){
 	 			ans = min(ans, DFS(v, used, r, j));
			}                                                    
		}
 	}
 	return ans;                    
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, l, x, y, a, b;
	char c;
	while(cin >> n >> m >> l){
	 	vector<vector<int>> v(n, vector<int>(n,0));
	 	vector<bool> used;
	 	vector<int> r(n);
	 	al.assign(n,0);
	 	for(int i=0; i<n; i++) al[i]=i;
	 	for(int i=0; i<n; i++) cin >> r[i];
		for(int i=0; i<m; i++){
			cin >> x >> y;
			v[y-1][x-1] = 1;
		}
		while(l--){
		 	cin >> c >> a;
		 	if(c == 'P'){
		 		used.assign(n, false);
				int ans = 1000000;
				//x=a-1;
				//while(al[x]!=a-1){x=al[x];}
				used[a-1]=true;
				for(int i = 0; i<n; i++)
					if(!used[i] && v[al[a-1]][i]==1){
						ans = min(ans, DFS(v, used, r, i));
					}
				if(ans==1000000) cout << "*\n";
				else cout << ans << '\n';
		 	}else{
				cin >> b;
				for(int i=0; i<n; i++){
					if(v[i][a-1]==1 && v[i][b-1]==1) continue;
				 	if(v[i][a-1]==1){v[i][a-1]=0; v[i][b-1]=1; continue;}
				 	if(v[i][b-1]==1){v[i][b-1]=0; v[i][a-1]=1; continue;}
				}
				v[a-1].swap(v[b-1]);
				//swap(r[a-1], r[b-1]);
				/*x = a-1;y = b-1;
				while(al[x]!=a-1){x=al[x];}
				while(al[y]!=b-1){y=al[y];}
				swap(al[x], al[y]);*/
		 	}
		}
	}
	return 0;
}