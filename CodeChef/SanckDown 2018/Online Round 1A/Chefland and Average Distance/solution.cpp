#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m;
	char c;
	cin >> t;
	while(t--){
	 	cin >> n >> m;
		list<ii> l;
		int pos = n+m;
		//vector<vector<int>> dist(n, vector<int>(m, pos));
		vector<int> ans(pos+1, 0);
		for(int i=0; i<n; i++){
		 	for(int j=0; j<m; j++){
				cin >> c;
				if(c=='1'){
					for(ii to : l){
						int aux = abs(to.first-i)+abs(to.second-j);
					 	ans[aux]++;
					}
					l.push_back(ii(i,j));					
				}
			}
		}
		int limit = pos-1;
		for(int i=1; i < limit; i++)
			cout << ans[i] << ((i == limit-1)? '\n' : ' ');
	}
	return 0;
}