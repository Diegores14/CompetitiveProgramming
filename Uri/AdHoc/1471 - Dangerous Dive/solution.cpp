#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int N, R,aux;
	while(cin >> N >> R){
		vector<int> v(N,0);
		for(int i=0; i<R; i++){
			cin >> aux; 
			v[--aux]++;
		}
		if(R==N) cout << "*\n";
		else{
			for(int i=0; i<N; i++)if(!v[i]) cout << i+1 << ' ';
			cout << '\n';
		}
	}
	return 0;

}