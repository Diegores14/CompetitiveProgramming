#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m;
	cin >> t;
	while(t--){
	 	cin >> n >> m;
		cout << ceil((n-2)/3.0)*ceil((m-2)/3.0) << '\n';
	}
	return 0;
}