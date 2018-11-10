#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, aux, aux1;
	bool sol=false;
	cin >> n >> m;
	vector<bool> bulbs(m, false);
	vector<vector<int>> v(n);
	cin >> aux;
	for(int i=0; i<aux; i++){
		cin >> aux1;
		bulbs[aux1-1]=true;
	}
	for(int i=0; i<n; i++){
	 	cin >> aux;
		v[i] = vector<int>(aux);
		for(int j=0; j<aux; j++){
			cin >> v[i][j];
			v[i][j]--;
		}
	}   
	int i=0;
	int j, tope = (n<<1);
	do{
	 	for(j=0; j<n && !sol; j++){
			i++;
			for(int to : v[j]){
			 	bulbs[to] = !bulbs[to];
			}
			sol = true;
			for(int k=0; k<m; k++){
				if(bulbs[k]){						
					sol=false;
					break;
				}
			}
		}
	}while(i<tope && !sol);
	cout << (sol? i : -1) << '\n';
	return 0;
}