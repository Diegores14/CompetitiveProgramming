#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, sum, aux;
	string s;
	while(cin >> n >> m, n || m){
		sum=0;
	 	for(int i=0; i<n; i++){cin >> s >> aux; sum+=aux;}
	 	cout << 3*m - sum << '\n';
	}
 	return 0;
}