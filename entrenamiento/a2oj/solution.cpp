#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)cin >> v[i];
	sort(v.begin(),v.end());
	if(n%2)cout << v[n/2] << '\n';
	else cout << v[n/2-1] << '\n';
	return 0;
}