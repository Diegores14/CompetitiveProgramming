#include <bits/stdc++.h>
using namespace std;

bool operator <(pair<int,int> a, pair<int,int> b){
 	return a.first < b.first;
}

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,aux;
	while(cin >> n, n){
	 	vector<pair<int,int>> v;
		for(int i=0; i<n; i++){cin >> aux;v.push_back(pair<int,int>(aux,i));}
		sort(v.begin(), v.end());
		cout << v[v.size()-2].second+1 << '\n'; 
		
	}
	return 0;
	
}