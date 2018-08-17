#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	 	vector<vector<int>> v;
	 	for(int i=1; i<10; i++)
	 		v.emplace_back(vector<int>(i));
	 	for(int i=0; i<9; i+=2) 
	 		for(int j=0; j<(int)v[i].size(); j+=2) cin >> v[i][j];
	 	for(int i=0; i<7; i+=2)
	 		v[8][i+1]=(v[6][i]-v[8][i]-v[8][i+2])/2;
	 	for(int i=7; i>=0; i--)
	 		for(int j=0; j<(int )v[i].size(); j++)v[i][j]=v[i+1][j]+v[i+1][j+1];
		for(int i=0; i<9; i++){
		 	for(int j=0; j<(int)v[i].size(); j++) cout << v[i][j] << ((j!=i)? ' ' : '\n');
		}
        }         
	return 0;
}