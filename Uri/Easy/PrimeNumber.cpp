#include <bits/stdc++.h>
using namespace std;
vector<int> criba(10000001, 1);

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, x;
	cin >> N;
	criba[0]=0;criba[1]=0;
	for(int i=2; i<=10000; i++){
	 	if(criba[i]==1){
		 	for(int j=i+i; j<10000001; j+=i){
			 	criba[j]=0;
			}
		}
	}

	while(N--){
	 	cin >> x;
		if(criba[x])cout << x << " eh primo\n";
		else cout << x << " nao eh primo\n";
	}
	
	return 0;
}