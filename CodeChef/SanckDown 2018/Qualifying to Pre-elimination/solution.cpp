#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, k;
	cin >> t;
	while(t--){
	 	cin >> n >> k;
		int ans=k;
		vector<int> v(n);
		for(int i=0; i<n; i++){
		 	cin >> v[i];
		}
		sort(v.begin(), v.end());
		int j = n-k;
		for(int i=j-1; i>=0; i--)
			if(v[j]==v[i])
				ans++;
			else
				break;
		cout << ans << '\n';
	}
	return 0;
}