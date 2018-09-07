#include <bits/stdc++.h>
using namespace std;

bool canMove(vector<vector<int>> & v, int a, int b){
 	for(int i=0; i<4; i++){
 	 	if(0<=i+a && i+a<4)
 	 		for(int j=0; j<4; j++)
 	 			if(0<=j+b && j+b<4)
 	 				if((v[i][j]!=0 && v[i+a][j+b]==0) || (v[i][j]==v[i+a][j+b] && v[i][j])){
 	 					return true;
 	 			       	}
 	}
 	return false;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	while(n--){            
		bool res=false;
		vector<string> ans;
	 	vector<vector<int>> v(4, vector<int>(4));
	 	for(int i=0; i<4; i++){
	 	 	for(int j=0; j<4; j++){ cin >> v[i][j];if(v[i][j]==2048)res=true;}
	 	}
	 	if(res){ cout << "NONE\n"; continue;}
	 	if(canMove(v,1,0))ans.push_back("DOWN");
		if(canMove(v,0,-1)) ans.push_back("LEFT");
		if(canMove(v,0,1)) ans.push_back("RIGHT");
		if(canMove(v,-1,0)) ans.push_back("UP");
		if(ans.size()==0) cout << "NONE\n";
		else 
			for(int i=0; i<(int)ans.size(); i++)
				cout << ans[i] << ((i==(int)ans.size()-1)? '\n' : ' ');
	}
	return 0;
}