#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	set<int> s;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)cin >> v[i][j];
	int a = n*2, i, j;
	while(a--){
	 	cin >> i >> j;
	 	s.insert(v[i-1][j-1]);
	}
	cout << s.size() << '\n';
 	return 0;
}