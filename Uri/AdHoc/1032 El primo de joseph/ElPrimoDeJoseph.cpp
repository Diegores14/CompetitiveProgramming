#include <bits/stdc++.h>
using namespace std;

vector<int> primos(50005), criba(50005, 1);
int N;

int josephus(int n){
 	if(n==1)return 0;
	int k=primos[N-n];
	return (josephus(n-1)+k)%n;
}

int main(){
 	ios_base::sync_with_stdio(false); cin.tie(NULL);
	criba[0] = criba[1] = 0;
	int p = 0;
	for(int i=2; i<50005; i++){
	 	if(criba[i]){
	 	 	primos[p++]=i;
			for(int j=i+i; j<50005;  j+=i){
			 	criba[j]=0;
			}
		}
	}	
	
	while(cin >> N && N){
	 	cout << josephus(N) + 1 << '\n';
	}
	return 0;
}