#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int mx=0, aux, n;
	map<int,int> m;
	cin >> n;
	while(n--){
	 	cin >> aux;
		m[aux]++;
		mx = max(mx,m[aux]);
	}
	cout << mx << '\n';
 	return 0;
}