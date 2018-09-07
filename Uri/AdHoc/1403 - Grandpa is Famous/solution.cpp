#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, r, aux;
	while(cin >> n >> r, n || r){
		map<int, int> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<r; j++){cin >> aux; m[aux]++;}
		}
		int first=-1, second=-1;
		for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
			if(it->second > first){first = it->second;}
			if(it->second > second && first != it->second) second=it->second;
		}
		for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
			if(it->second == second) cout << it->first << ' '; 
		cout << '\n';
	}
 	return 0;
}