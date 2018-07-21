#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, c, m, answer, mx;
	cin >> t;
	while(t--){
		answer = 0;
	 	cin >> n >> c >> m;
	 	vector<int> v(m);
	 	for(int i=0; i<m; i++)cin >> v[i];
	 	sort(v.begin(), v.end(), greater<int>());
		for(int i=0; i<m; i+=c){
			mx=0;
		 	for(int j=0; j<c && j+i<m; j++)mx = max(mx, v[j+i]);
		 	answer += 2*mx;
		}
		cout << answer << '\n';
	}
 	return 0;
}