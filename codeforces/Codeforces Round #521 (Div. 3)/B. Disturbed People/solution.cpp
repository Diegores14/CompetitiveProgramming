#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &i: v)
		cin >> i;
	n--;
	int ans = 0;
	for(int i=1; i<n; i++){
	 	if(v[i]==0 && v[i-1] == 1 && v[i+1] == 1){
	 	 	ans++;
	 	 	v[i+1] = 0;
	 	}
	}
	cout << ans << '\n';
	return 0;
}