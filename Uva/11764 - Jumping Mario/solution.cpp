#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	for(int k=1; k<=t; k++){
	       cin >> n;
		vector<int> v(n);
		for(int &i : v){
		 	cin >> i;
		}
		int ans1 = 0, ans2 = 0;
		for(int i=1; i<n; i++){
		        if(v[i-1] < v[i])
				ans1++;
			if(v[i-1] > v[i])
				ans2++;
		}	
		cout << "Case " << k << ": " << ans1 << ' ' << ans2 << '\n';
	}	
	return 0;
}