#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N, x;
	cin >> N;
	while(N--){
	 	cin >> x;     	
		int sum=0;
		for(int i=1; i<=x/2; i++) if(x%i==0)sum+=i;
		if(x==sum)cout << x << " eh perfeito\n";
		else cout << x << " nao eh perfeito\n";
	}
}