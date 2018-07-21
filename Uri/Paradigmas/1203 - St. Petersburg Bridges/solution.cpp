#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cint.tie(NULL);
	int r, k, a, b, odd;
	while(cin >> r >> k){
		odd=0;
	 	vector<vector<int>> v(r+1);
	 	for(int i=0; i<k; i++){
	 	 	cin >> a >> b;
	 	 	v[a].push_back(b);
	 	 	v[b].push_back(a);
	 	}
	 	for(int i=1; i<=r; i++)odd += v[i].size()%i;
	 	cout << ((odd == 2 || odd == 0)? "S\n" : "N\n");
	}
 	return 0;
}