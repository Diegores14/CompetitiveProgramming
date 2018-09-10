#include <bits/stdc++.h>
using namespace std;

int DFS(int i, vector<bool> & used, vector<int> & tam, vector<int> & v, int cant){
 	if(used[i])return cant;
	used[i]=true;
	//cout << "hello\n";
	return tam[i] = DFS(v[i]-1, used, tam, v, cant+1);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long R;
	int N;
	while(cin >> N >> R){		
		vector<int> v(N);
		vector<bool> used(N, false);
		vector<int> tam(N);
		for(int i=0; i<N; i++)cin >> v[i];
		for(int i=0; i<N; i++){
		 	if(!used[i])DFS(i, used, tam, v, 0);
		}
		for(int i=0; i<N; i++){
		 	int c=R%tam[i];
			int j=i;
			for(int k=0; k<c; k++) j=v[j]-1;
			cout << j+1 << ((i==N-1)? '\n' : ' ');
		}		
	}
	return 0;
}