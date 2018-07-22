#include <bits/stdc++.h>
using namespace std;

bool rowsAndColumns(int v[9][9]){
	set<int> s;
 	for(int i=0; i<9; i++){
 		s.erase(s.begin(),s.end());
 	 	for(int j=0; j<9; j++){
 	 		if(s.count(v[i][j]))return false;
 	 		else s.insert(v[i][j]);
		}
 	}
 	for(int i=0; i<9; i++){
 		s.erase(s.begin(),s.end());
 	 	for(int j=0; j<9; j++){
 	 		if(s.count(v[j][i]))return false;
 	 		else s.insert(v[j][i]);
		}
 	}
 	return true;
}

bool subMatrices(int v[9][9], int a, int b){
	set<int> s;
	for(int i=0; i<3; i++){
	 	for(int j=0; j<3; j++){
	 	 	if(s.count(v[a+i][b+j]))return false;
	 	 	else s.insert(v[a+i][b+j]);
	 	}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n;
        bool answer;
        cin >> n;
        int v[9][9];
	for(int k=1; k<=n; k++){
		answer = true;
		cout << "Instancia " << k << '\n';
	 	for(int i=0; i<9; i++){
	 	 	for(int j=0; j<9; j++){
	 	 	 	cin >> v[i][j];
	 	 	}
	 	}
	 	if(!rowsAndColumns(v))answer=false;
	 	else for(int i=0; i<9; i+=3)
	 		for(int j=0; j<9; j+=3)if(!subMatrices(v, i, j)){answer=false;break;}
	 	cout << ((answer)? "SIM\n\n" : "NAO\n\n");

	}
 	return 0;
}