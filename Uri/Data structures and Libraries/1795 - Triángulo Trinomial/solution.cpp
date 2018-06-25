#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>> v(21);
	v[0].push_back(1);
	for(int i=0; i<3; i++)v[1].push_back(1); 
	for(int i=2; i<=20; i++){
		v[i].push_back(1);
		v[i].push_back(i);
		for(int j=0; j<(int)v[i-1].size()-2; j++){
		 	v[i].push_back(v[i-1][j]+v[i-1][j+1]+v[i-1][j+2]);
		}
		v[i].push_back(i);
		v[i].push_back(1);
	}
	unsigned int n,sum=0;
	cin >> n;
	for(int to : v[n])sum+=to;
	cout << sum << '\n';
 	return 0;
}