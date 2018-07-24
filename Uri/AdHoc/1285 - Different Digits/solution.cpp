#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, v[10], aux, answer;
	while(cin >> n >> m){
		answer=0;
	 	for(int i=n; i<=m; i++){
	 	 	memset(v,0,sizeof v);
	 	 	aux=i;
	 	 	while(aux){
	 	 	 	if(v[aux%10])break;
	 	 	 	else v[aux%10]=1;
	 	 		aux/=10;
	 	 	}
	 	 	if(aux==0)answer++;
	 	}
		cout << answer << '\n';
	}
 	return 0;
}