#include <bits/stdc++.h>
using namespace std;
vector<bool> criba(100000002, true);

int main(){
	ios_base::sync_with_stdio(false);
	criba[0]=criba[1]=false;
	int k=0;
	for(long long i=2;i<=100000000; i++){
	 	if(criba[i]){
	 	 	if(!(k%100))cout << i << '\n';
			for(long long j=i*i; j<=100000000; j+=i){
			 	criba[j]=false;
			}
			k++;
		}
	}
	return 0;
}