#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m;
	cin >> t;
	while(t--){
		map<int,int> table1, table2;
		cin >> n >> m;
		int aux;
		for(int i=0; i<n; i++){
			cin >> aux;
			if(aux==0){
			 	n--;
				continue;
			}
		 	table1[aux]++;
		}
		for(int i=0; i<m; i++){
			cin >> aux;
			if(aux==0){
			 	m--;
				continue;
			}
		 	table2[aux]++;
		}
		bool flag=true;
		if(n==m && table1.size() == table2.size()){
			for(auto it: table1){
			 	if(!(table2.count(it.first) && it.second == table2[it.first])){
					flag = false;
					break;
				}
			} 
			
		}else{
		        flag = false;
		}	
		if(flag)
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
	return 0;
}