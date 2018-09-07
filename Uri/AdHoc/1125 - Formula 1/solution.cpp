#include <bits/stdc++.h>
using namespace std;

struct node{
  	int a, b;
  	node(){a=0; b=0;}
};

bool operator <(node a, node b){
 	if(a.b == b.b) return a.a > b.a;
 	return a.b < b.b;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, s, k;
	while(cin >> n >> m, n || m){
	 	vector<vector<int>> v(n, vector<int>(m));
	 	for(int i = 0; i<n; i++)
	 	 	for(int j=0; j<m; j++) cin  >> v[i][j];
		cin >> s;
		while(s--){
		 	cin >> k;
		 	vector<node> v1(m);
		 	for(int i=0; i<m; i++) v1[i].a=i;
		 	vector<int> v2(m, 0);
		 	for(int i=0; i<k; i++) cin >> v2[i];
		 	for(int i=0; i<n; i++)
		 		for(int j=0; j<m; j++){
		 		 	v1[j].b += v2[v[i][j]-1];
		 		}
			sort(v1.begin(), v1.end());
			cout << v1[v1.size()-1].a + 1;
			for(int j=m-2; j>=0; j--)if(v1[v1.size()-1].b == v1[j].b) cout << ' ' << v1[j].a + 1; else break;
			cout << '\n';
		}
	}
	return 0;
}