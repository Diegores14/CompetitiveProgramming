#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, mx=0, tim=0;
	cin >> n >> m;
	map<int,int> ma;
	vector<int> v1(n), v2(n);
	for(int i=0; i<n; i++) cin >> v1[i];
	for(int i=0; i<m; i++) cin >> v2[i];
	for(int i=0; i<n; i++){
	 	for(int j=0; j<m; j++)if(v2[j]-v1[i]>=0)ma[v2[j]-v1[i]]++;
	}
	for(map<int,int>::iterator it = ma.begin(); it != ma.end(); ++it)if(mx<it->second){ mx=it->second; tim = it->first;}
	cout << tim << '\n';
 	return 0;
}