#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(5, vector<int>(5));
vector<vector<bool>> used(5, vector<bool>(5));

bool backtracking(int i, int j){      
 	if(i==5 || j==5 || i==-1 || j==-1 || v[i][j]==1 || used[i][j]) return false;
 	if(i==4 && j==4){return true;}
 	used[i][j]=true;
	if(backtracking(i,j+1))return true;
	if(backtracking(i+1,j))return true;
	if(backtracking(i-1,j))return true;
	if(backtracking(i,j-1))return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){
	 	for(int i=0; i<5; i++)
	 	 	for(int j=0; j<5; j++){cin >> v[i][j];used[i][j]=false;}
	 	 cout << ((backtracking(0,0))? "COPS\n" : "ROBBERS\n");
	}
 	return 0;
}