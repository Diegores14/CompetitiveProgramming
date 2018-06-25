#include <bits/stdc++.h>
using namespace std;
int EveryProblemWasSolved(int v[], int a){
 	for(int i=0; i<a; i++){
 	 	if(v[i]==0)return 0;
	}
	return 1;
}

int EveryoneSolvedAtLeastOneProblem(int v[], int a, int x){
 	for(int i=0; i<a; i++)
		if(v[i]==x) return 0;
	return 1;
}

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	while(cin>>x>>y, x || y){
		int v[x][y];
		for(int i=0; i<x; i++)
			for(int j=0; j<y; j++) cin >> v[i][j];
		int v1[y], v2[x], aux=0, res=0;
		for(int i=0; i<y; i++){
			aux=0;
			for(int j=0; j<x; j++) aux+=v[j][i];
			v1[i]=aux;
		}
		for(int i=0; i<x; i++){
			aux=0;
			for(int j=0; j<y; j++) aux+=v[i][j];
			v2[i]=aux;
		}
		res += EveryProblemWasSolved(v1,y);
		res += EveryoneSolvedAtLeastOneProblem(v1, y, x);
		res += EveryProblemWasSolved(v2,x);
		res += EveryoneSolvedAtLeastOneProblem(v2, x, y);
		cout << res << '\n';
	}
	return 0;
}