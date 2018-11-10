#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	vector<bool> criba(1000005, true);
	criba[0]=criba[1]=false;
	for(int i=2; i*i<=1000005; i++){
		if(criba[i])
	 	for(int j=i*i; j<1000005; j+=i){
	 	 	criba[j]=false;
		}
	}
	vector<int> prefix(1000005, 0);
	for(int i=1; i<1000005; i++){
		prefix[i] = prefix[i-1];
	 	if(criba[i])prefix[i]++;
	}
	while(cin >> a >> b, a && b){
	 	cout << prefix[b]-prefix[a-1] << '\n';
	}
 	return 0;
}