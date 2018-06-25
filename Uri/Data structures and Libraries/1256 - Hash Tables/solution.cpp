#include <bits/stdc++.h>
using namespace std;

int main(){      
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n, m, c, aux, index;
	cin >> n;
	while(n--){
		cin >> m >> c;
		vector<vector<int>> hash(m);
		while(c--){
			cin >> aux;
			index = aux%m;
			hash[index].push_back(aux);
		}
		for(int i=0; i<m; i++){
			cout << i << " -> ";
		 	for(int to : hash[i]){
		 	 	cout << to << " -> ";
			}
			cout << '\\' << '\n';
		}
		if(n)cout << '\n';
	}
	return 0;
}