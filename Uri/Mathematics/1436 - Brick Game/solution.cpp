#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, h;
	cin >> n;
	for(int i=1; i<=n; i++){
	 	cin >> h;
		cout << "Case " << i << ": ";
		vector<int> v(h);
		for(int j=0; j<h; j++)cin >> v[j];
		cout << v[h/2] << '\n';
	}
 	return 0;
}